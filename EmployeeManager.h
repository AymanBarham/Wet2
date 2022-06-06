//
// Created by omarz on 06/06/2022.
//

#ifndef WET2_EmployeeManager_H
#define WET2_EmployeeManager_H

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

class EmployeeManager{
    UnionFindCompanies* allCompanies;
    HashTable allEmployees;
    RankTree<Employee, CompareEmpBySalary> allEmployeesWithSalary;

public:
    EmployeeManager(int k): allCompanies(new UnionFindCompanies(k)){}
    ~EmployeeManager(){
        delete allCompanies;
    }

    StatusType AddEmployee(int employeeID, int companyID, int grade);

    StatusType RemoveEmployee(int employeeID);

    StatusType AcquireCompany(int companyID1, int companyID2, double factor);

    StatusType EmployeeSalaryIncrease(int employeeID, int salaryIncrease);

    StatusType PromoteEmployee(int employeeID, int bumpGrade);

    StatusType SumOfBumpGradeBetweenTopWorkersByGroup(int companyID, int m, void * sumBumpGrade);

    StatusType AverageBumpGradeBetweenSalaryByGroup(int companyID, int lowerSalary, int higherSalary, void * averageBumpGrade);

    StatusType CompanyValue(int companyID, void * standing);

};

#endif //WET2_EmployeeManager_H
