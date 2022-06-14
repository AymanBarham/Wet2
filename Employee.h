
#ifndef WET1_EMPLOYEE_H
#define WET1_EMPLOYEE_H

#include <iostream>
#include <memory>
//#include "Company.h"

using std::shared_ptr;
using std::weak_ptr;


class Company;

class Employee {
public:
    long id;
    long grade;
    long salary;
    weak_ptr<Company> company;

    Employee(long id, long grade, long salary, shared_ptr<Company> company): id(id),
                grade(grade), salary(salary), company(company) {}

    friend bool operator==(const Employee& e1, const Employee& e2);
};

bool operator==(const Employee& e1, const Employee& e2) {
    return e1.id == e2.id;
}
#endif //WET1_EMPLOYEE_H
