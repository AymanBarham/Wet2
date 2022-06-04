//
// Created by Ayman Barham on 20/04/2022.
//

#ifndef WET1_COMPAREEMPBYID_H
#define WET1_COMPAREEMPBYID_H

#include <iostream>
#include "Employee.h"
#include <memory>
using std::shared_ptr;

class CompareEmpByID {
public:
    bool operator()(shared_ptr<Employee> e1, shared_ptr<Employee> e2) const {
        return e1->id < e2->id;
    }
};

#endif //WET1_COMPAREEMPBYID_H
