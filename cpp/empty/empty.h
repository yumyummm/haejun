#ifndef EMPTY_H
#define EMPTY_H

class Empty {
public:
    //Empty() {}
    //Empty(const Empty&) {memberwise copy} 
    //~Empty() {}

    //Empty& operator=(const Empty&) {memberwise copy return *this;}

    //Empty* operator&() {return this;} 자기 자신의 주소값을 자동으로 연산해주는 식
    //const Empty* operator&() const {return this;} 함수 인자의 타입과 개수가 위와 같지만 const붙고 안 붙고로 구분되므로 함수중복 가능! 상수 객체를 통해서 호출할 때 호출됨.
};

#endif 
