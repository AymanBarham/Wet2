
#ifndef WET1_COMPANY_H
#define WET1_COMPANY_H

#include <iostream>
#include "Employee.h"
#include "CompareEmpByID.h"
#include "CompareEmpBySalary.h"
#include "AVLTree.h"

using std::shared_ptr;

class Company {
public:
    int id;
    int value;
    AVLTree<Employee, CompareEmpByID> employeesByID;
    AVLTree<Employee, CompareEmpBySalary> employeesBySalary;

    Company(int id, int value): id(id), value(value) {}

    friend bool operator==(const Company& c1, const Company& c2);

    bool isWorking() const {
        return !employeesByID.isEmpty();
    }

};

bool operator==(const Company& c1, const Company& c2) {
    return c1.id == c2.id;
}


#endif //WET1_COMPANY_H
