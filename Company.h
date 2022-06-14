
#ifndef WET1_COMPANY_H
#define WET1_COMPANY_H

#include <iostream>
#include "Employee.h"
#include "CompareEmpByID.h"
#include "CompareEmpBySalary.h"
#include "AVLTree.h"
#include "RankTree.h"
#include "HashTable.h"

using std::shared_ptr;


class Company {
public:
    long id;
    double value;
//    AVLTree<Employee, CompareEmpByID> employeesByID;
//    AVLTree<Employee, CompareEmpBySalary> employeesBySalary;

    RankTree<Employee, CompareEmpBySalary> employeesWithSalary;
    HashTable companyEmployees;
    Company(long id, double value): id(id), value(value) {}

    friend bool operator==(const Company& c1, const Company& c2);

//    bool isWorking() const {
//        return !employeesByID.isEmpty();
//    }

};

bool operator==(const Company& c1, const Company& c2) {
    return c1.id == c2.id;
}


#endif //WET1_COMPANY_H
