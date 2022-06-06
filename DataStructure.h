//
// Created by omarz on 06/06/2022.
//

#ifndef AVLTREE_H_DATASTRUCTURE_H
#define AVLTREE_H_DATASTRUCTURE_H

#include "UnionFindCompanies.h"
#include "HashTable.h"
#include "RankTree.h"
#include "AVLTree.h"
#include "Company.h"
#include "Employee.h"
#include "CompareEmpByID.h"
#include "CompareEmpBySalary.h.h"
#include "library2.h"

#include <iostream>
#include <memory>
using std::shared_ptr;

class DataStructure{
    UnionFindCompanies allCompanies;
    HashTable allEmployees;
    RankTree<Employee, CompareEmpBySalary> allEmployeesWithSalary;

public:
    DataStructure() = default;
    ~DataStructure() = default;

    

};

#endif //AVLTREE_H_DATASTRUCTURE_H
