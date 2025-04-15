#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "string.h"

class Employee{
private:
    int id;
    String name;
    Employee *pManager;
    //
    Employee(const Employee& rhs); //복사생성자 (쓰기 싫은 멤버함수는 여기에 쓰면 컴파일러가 자동으로 만들지 않음.)
    Employee& operator=(const Employee& rhs); //치환연산식 (위와 마찬가지임.)
public:
    Employee(int id, String name, Employee *pManager); 
    //1. ~Employee() {} 
    
    //2. Employee() {} is not generated (why? 위에 명시적인 다른 생성자가 있어서!)
    //3. Employee(const Employee& rhs) {memberwise copy}
    //4. Employee& operator=(const Employee& rhs) {memberwise copy return *this;}

    //5. Employee* operator&() {return this;}
    //6. const Employee* operator&() const {return this;}  //결론: 지금 이 코드에서는 1, 5, 6번만 만들어지고 2,3,4는 만들어지지 않음.

    int getId();
    String getName();
    Employee *getManager();
//set함수는 사원 정보 알아보는 코드에 어울리지 않음.
    bool isManager();
};

#endif
