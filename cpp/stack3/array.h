#ifndef ARRAY_H
#define ARRAY_H

//#define ARRAY_SIZE 100 이렇게 쓰면 자료형이 정확한지 검증이 안 되기 때문에 다음과 같이 씀. extern const int ARRAY_SIZE; 그런데 전역데이터지만 특정 클래스와만 관련된 데이터의 경우 클래스 안에 넣어서 8번처럼 스태틱 멤버변수로 만듦. 

class Array{
    private:
    static const int ARRAY_SIZE; //전역데이터지만 특정 클래스와만 관련된 데이터의 경우 스태틱 멤버변수로 만듦.
    int *pArr_;
    int size_;
    
    public:
    static int getDefaultArraySize(); //8번의 ARRAY_SIZE를 public에 안 쓰고 private에 쓰고 싶다면, 이렇게 허용된 연산을 따로 만들어줘서 접근해야 함!
    //Array();
    explicit Array(int size = ARRAY_SIZE);
    Array(const int *pArr, int size);
    Array(const Array& rhs);
    ~Array();
    
    Array& operator=(const Array& rhs);
    
    bool operator==(const Array& rhs) const;

    int& operator[](int index);
    const int& operator[](int index) const;

    //Array(const Array&)
    //Array& operator=(const Array&)
    //Array *operator&() {return *this;}
    //const Array *operator&() const{return *this;}

    int size() const;


};
#endif