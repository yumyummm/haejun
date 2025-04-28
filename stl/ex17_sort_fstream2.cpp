#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <numeric>
#include <algorithm>  // sort, partition, merge 등 알고리즘을 위한 헤더

using namespace std;

class Student
{
private:
    string name_;
    vector<int> scores_;

public:
    Student(const string& name, const vector<int> scores)
        : name_(name), scores_(scores) {}

    int totalScore() const
    {
        return accumulate(scores_.begin(), scores_.end(), 0);
    }

    int averageScore() const {
        return totalScore() / scores_.size();
    }

    void print() const
    {
        cout << "이름 : " << name_ << endl;
        cout << "점수 : ";
        for (const auto& v : scores_)
            cout << v << " ";
        cout << endl;
        cout << "총점 : " << totalScore() << endl;
        cout << "평균 : " << averageScore() << endl;
        cout << "-----------------------------------------" << endl;
    }

    // operator<를 오버로딩해서 평균 점수 기준으로 비교
    bool operator<(const Student& other) const
    {
        return averageScore() < other.averageScore();
    }
};

int main()
{
    ifstream file("/home/yujin/haejun/stl/10.txt");
    vector<Student> students;

    string line, name;
    vector<int> scores;
    int score;

    // 학생 정보 파일 읽어오기
    while (getline(file, line))
    {
        istringstream iss(line);
        iss >> name;
        while (iss >> score)
            scores.push_back(score);
        students.emplace_back(name, scores);
        scores.clear();
    }
    file.close();

    // 학생들의 이름만 출력 (디버깅용)
    for (const auto& student : students)
        cout << student.name_ << " ";
    cout << endl;

    // 평균 점수로 학생들 정렬
    sort(students.begin(), students.end());

    // 합격/불합격 기준으로 분리
    auto fail_bound = partition(students.begin(), students.end(), [](const Student& st)
                                 { return st.averageScore() < 60; });

    vector<Student> fail_students(students.begin(), fail_bound);
    vector<Student> success_students(fail_bound, students.end());

    // 불합격 학생들 출력
    cout << "불합격 학생들:" << endl;
    for (const auto& student : fail_students)
        student.print();

    // 합격 학생들 출력
    cout << "합격 학생들:" << endl;
    for (const auto& student : success_students)
        student.print();

    // 합격/불합격 학생들을 합쳐서 출력
    vector<Student> merge_students;
    merge(fail_students.begin(), fail_students.end(), success_students.begin(), success_students.end(), back_inserter(merge_students));

    cout << "합친 학생들:" << endl;
    for (const auto& student : merge_students)
        student.print();

    return 0;
}
