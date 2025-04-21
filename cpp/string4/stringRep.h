#ifndef STRING_REP_H
#define STRING_REP_H

class StringRep{
friend class String; //스트링 클래스쪽에 있는 멤버함수는 스트링알이피 클래스의 프라이빗 멤버에 접근할 수 있게 됨.
private:
    char *str_;
    int len_;
    int rc; // ref count

    StringRep();
    StringRep(const char* s);
    ~StringRep();

public:

};

#endif