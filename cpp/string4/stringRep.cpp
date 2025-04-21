#include"stringRep.h"
#include <cassert>
#include <cstring>

StringRep::StringRep()
: str_(new char[1]), len_(0)
{
    assert(str_ );
}


StringRep::StringRep(const char* str)
    : str_(new char[strlen(str) + 1]), len_(strlen(str)) // +1을 추가해야 합니다.
{
    assert(str_); // 메모리 할당 실패 시, 프로그램 종료
    strcpy(str_, str); // 문자열 복사
}

StringRep::~StringRep()

{
    delete[] str_;
}