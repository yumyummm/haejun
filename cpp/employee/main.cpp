#include <iostream>
#include "employee.h"

void printEmployee(Employee *p)
{
    std::cout << "id: " << p->getId() << " name: " << p->getName() << " manager: ";
    std::cout << ((p->isManager() )? "" : p->getManager()->getName()) << std::endl;
}

int main()
{
    // Employee e1(1, "Park Jungseok", NULL);
    // Employee e2(2, "Sung Youngho", &e1);
    // Employee e3(3, "Choi Sugil", &e2);
    // Employee e4(4, "Cho Minsung", &e3);
    // Employee e5(5, "Min Byunghun", &e4); 

    // Employee e6 = e1 복사생성자
    // e1 = e2; 치환연산식 (이 둘 다 사원정보 관리하는 코드에 안 어울림.)

    //Employee employees[10]; // default constructor가 없는데 자동으로 10번 호출돼서 에러 발생함.
    Employee* pEmployees[10];
    pEmployees[0] = new Employee(1, "Park Jungseok", NULL);
    pEmployees[1] = new Employee(2, "Sung Youngho", pEmployees[0]);
    pEmployees[2] = new Employee(3, "Choi Sugil", pEmployees[1]);
    pEmployees[3] = new Employee(4, "Cho Minsung", pEmployees[2]);
    pEmployees[4] = new Employee(5, "Min Byunghun", pEmployees[3]);

    for(int i =0 ; i < 5 ;++i){
        printEmployee(pEmployees[i]);
    }
    for(int i = 0; i < 5; ++i){
        delete pEmployees[i];
    }

    // std::cout << "Employee ID: " << e1.getId() << "Employee Name: " << e1.getNmae() << std::endl;
    // std::cout << "Employee Name: " << e2.getName() << std::endl;

    return 0;
}
