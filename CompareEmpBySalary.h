//
// Created by Ayman Barham on 20/04/2022.
//

#ifndef WET1_COMPAREEMPBYSALARY_H
#define WET1_COMPAREEMPBYSALARY_H


#include <iostream>
#include "Employee.h"
#include "CompareEmpByID.h"
#include <memory>
using std::shared_ptr;

class CompareEmpBySalary {
public:
    bool operator()(shared_ptr<Employee> e1, shared_ptr<Employee> e2) const {
        if (e1->salary == e2->salary) {
            CompareEmpByID comparer;
            return comparer(e1, e2);
        }
        return e1->salary < e2->salary;
    }
};


#endif //WET1_COMPAREEMPBYSALARY_H
