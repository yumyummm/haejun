/*입력함수 frame 10frma인데 300점까지 계산할 수 있는 게임. 2번의 기회가 주어지고 첫 번째 점수 10점 만점.  그냥 볼링 룰로 만들어라 점수는 랜덤 혹은 사용자 입력으로 구현 여러 명이 동시 사용*/
/*사용자명, 점수, 날짜 인식해서 1번 테이블 데이터 베이스를 만들고 끝나면 업로드 2번째 테이블에는 사용자명, 월별 날짜별 횟수(사용자가 몇 번 게임을 했는)를 기록한 컬럼이 2개인 테이블*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <mysql/mysql.h> // MySQL 헤더 파일 추가

#define cls system("cls")
#define MAX_NAME_LENGTH 40
#define MAX_FRAMES 10

typedef struct {
  int firstRoll;
  int secondRoll;
  int score;
  int isStrike;
  int isSpare;
} Frame;

typedef struct {
  MYSQL *conn;
  const char *host;
  const char *user;
  const char *pass;
  const char *db;
  unsigned int port;
} MySQLConnection;

void startScreen(char *playerName) {
  printf("___________ 볼링의 신 _____________\n");
  printf(" ◕̀  ‧̫ ◕)⊃=͟͟͞͞◓ 🎳🎳\n");
  printf("도전장을 내민 당신의 이름은?: ");
  fgets(playerName, MAX_NAME_LENGTH, stdin);
  playerName[strcspn(playerName, "\n")] = '\0';
  printf("%s, 도전을 받아줄게!\n", playerName);
  printf("엔터를 누르면 대결 시작~!\n");
  getchar();
}

void endScreen(char *playerName, int playerScore, int computerScore) {
  printf("-------------------------\n");
  printf("게임 끝~!\n");
  printf("-------------------------\n");

  printf("%s의 점수는: %d\n", playerName, playerScore);
  printf("나의 점수는: %d\n", computerScore);
  if (playerScore > computerScore) {
    printf("아쉽지만 %s의 승리 ｡° ૮₍°´ᯅ`°₎ა °｡\n", playerName);
  } else if (playerScore < computerScore) {
    printf("안됐지만 나의 승리! ლ(´ڡ`ლ) \n");
  } else {
    printf("이런, 비기다니... (︶︹︺) \n");
  }

  printf("엔터를 누르면 게임 종료~!\n");
  getchar();
}

bool initMySQL(MySQLConnection *mysql) {
  // 기본 연결 정보 설정
  mysql->host = "localhost";
  mysql->user = "root";
  mysql->pass = "0000";
  mysql->db = "bowling_db";
  mysql->port = 3306;

  // MySQL 초기화
  mysql->conn = mysql_init(NULL);
  if (mysql->conn == NULL) {
    fprintf(stderr, "MySQL 초기화 실패\n");
    return false;
  }

  // MySQL 서버 연결
  if (!mysql_real_connect(mysql->conn, mysql->host, mysql->user, mysql->pass, mysql->db, mysql->port, NULL, 0)) {
    fprintf(stderr, "MySQL 연결 실패: %s\n", mysql_error(mysql->conn));
    return false;
  }

  printf("MySQL 데이터베이스에 연결되었습니다.\n");
  return true;
}

void closeMySQL(MySQLConnection *mysql) {
  if (mysql->conn != NULL) {
    mysql_close(mysql->conn);
    mysql->conn = NULL;
    printf("MySQL 연결이 종료되었습니다.\n");
  }
}

bool saveScore(MySQLConnection *mysql, const char *username, int score) {
  char query[255];

  // 현재 날짜 가져오기
  time_t t = time(NULL);
  struct tm *tm = localtime(&t);
  char date[11];
  strftime(date, sizeof(date), "%Y-%m-%d", tm);

  // 쿼리 준비
  sprintf(query, "INSERT INTO score_records (username, play_date, score) VALUES ('%s', '%s', %d)", username, date, score);

  // 쿼리 실행
  if (mysql_query(mysql->conn, query)) {
    fprintf(stderr, "점수 저장 실패: %s\n", mysql_error(mysql->conn));
    return false;
  }

  printf("점수가 성공적으로 저장되었습니다!\n");
  return true;
}

bool updateMonthlyStats(MySQLConnection *mysql) {
  char query[512];

  // 월별 통계 업데이트 쿼리
  sprintf(query, "INSERT INTO user_monthly_stats (username, year, month, play_count) "
                 "SELECT username, YEAR(play_date), MONTH(play_date), COUNT(*) "
                 "FROM score_records "
                 "GROUP BY username, YEAR(play_date), MONTH(play_date) "
                 "ON DUPLICATE KEY UPDATE play_count = VALUES(play_count)");

  // 쿼리 실행
  if (mysql_query(mysql->conn, query)) {
    fprintf(stderr, "월별 통계 업데이트 실패: %s\n", mysql_error(mysql->conn));
    return false;
  }

  printf("월별 통계가 업데이트되었습니다.\n");
  return true;
}

void playGame(char *playerName, MySQLConnection *mysql) {
  Frame playerFrames[MAX_FRAMES] = {0};
  Frame computerFrames[MAX_FRAMES] = {0};
  int playerTotalScore = 0, computerTotalScore = 0;

  for (int frame = 0; frame < MAX_FRAMES; ++frame) {
    printf("===============제%d차 경기===============\n", frame + 1);

    printf("\n<%s의 차례> 엔터를 눌러 볼링공을 던져봐!\n", playerName);
    getchar();
    playerFrames[frame].firstRoll = rollBall(10);
    printf("( ˆoˆ )/​%s의 볼링공이 %d개의 핀에 적중~!\n", playerName, playerFrames[frame].firstRoll);

    if (playerFrames[frame].firstRoll == 10) {
      printf("스트라이크!(=^・・^)ﾉ\n");
      playerFrames[frame].isStrike = 1;
    } else {
      printf("\n다시 한번 엔터를 눌러 공을 던져봐!\n");
      getchar();
      playerFrames[frame].secondRoll = rollBall(10 - playerFrames[frame].firstRoll);
      printf("%s의 공이 %d개의 핀에 추가로 적중!\n", playerName, playerFrames[frame].secondRoll);
      if (playerFrames[frame].firstRoll + playerFrames[frame].secondRoll == 10) {
        printf("스페어! (=^・・^)ﾉ\n");
        playerFrames[frame].isSpare = 1;
      }
    }

    printf("\n<나의 차례> 내 솜씨를 보여주지!\n");
    computerFrames[frame].firstRoll = rollBall(10);
    printf("내 공이 %d개의 핀을 쓰러뜨렸어!\n", computerFrames[frame].firstRoll);

    if (computerFrames[frame].firstRoll == 10) {
      printf("스트라이크!\n");
      computerFrames[frame].isStrike = 1;
    } else {
      printf("\n할 수 없지, 한 번 더 던져야겠어...\n");
      computerFrames[frame].secondRoll = rollBall(10 - computerFrames[frame].firstRoll);
      printf("내 공이 %d개의 핀을 더 쓰러뜨렸어!\n", computerFrames[frame].secondRoll);
    }

    printf("\n");

    calculateScore(playerFrames, &playerTotalScore);
    calculateScore(computerFrames, &computerTotalScore);
  }

  endScreen(playerName, playerTotalScore, computerTotalScore);

  // 점수 저장 및 월별 통계 업데이트
  saveScore(mysql, playerName, playerTotalScore);
  updateMonthlyStats(mysql);
}

int main() {
  char playerName[MAX_NAME_LENGTH];
  srand(time(NULL));
  MySQLConnection mysql;

  if (!initMySQL(&mysql)) {
    fprintf(stderr, "MySQL 초기화 실패\n");
    return 1;
  }

  startScreen(playerName);
  playGame(playerName, &mysql);
  closeMySQL(&mysql);
  return 0;
}