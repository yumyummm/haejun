#ifndef INVALID_INDEX_H
#define INVALID_INDEX_H


class InvalidIndex{
private:
    int index_;
public:
    InvalidIndex(int index);

    int invalid() const; //잘못 사용한 인덱스 값을 리턴하는 get함수
};

#endif