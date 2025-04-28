#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int serv_sock;
    struct sockaddr_in serv_addr;

    if (argc != 3)
    {
        printf("사용법: %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    serv_sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓 생성
    if (serv_sock == -1)
    {
        perror("socket");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(serv_sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1)
    {
        perror("connect");
        close(serv_sock);
        exit(1);
    }

    char message[] = "Hello, TCP IP!!";

    if (send(serv_sock, message, strlen(message), 0) == -1)
    {
        perror("send");
        close(serv_sock);
        exit(1);
    }

    printf("메세지를 서버로 보냈습니다: %s\n", message);

    close(serv_sock);

    return 0;
}
