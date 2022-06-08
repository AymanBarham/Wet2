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
    int numOfCompanies;
    int numOfZeroSalaryEmployees;
    int gradeSumOfZeroSalaryEmployees;
    int* numOfZeroSalaryCompany;
    int* sumOfGradesZeroSalaryCompany;
public:
    EmployeeManager(int k): allCompanies(new UnionFindCompanies(k)), numOfCompanies(k),
                            numOfZeroSalaryEmployees(0), gradeSumOfZeroSalaryEmployees(0),
                            numOfZeroSalaryCompany(new int[k + 1]),
                            sumOfGradesZeroSalaryCompany(new int[k + 1]){
        for(int i = 0 ; i < k + 1 ; ++i){
            numOfZeroSalaryCompany[i] = 0;
            sumOfGradesZeroSalaryCompany[i] = 0;
        }
    }
    ~EmployeeManager(){
        delete allCompanies;
        delete[] numOfZeroSalaryCompany;
        delete[] sumOfGradesZeroSalaryCompany;
    }


    ////done
    StatusType AddEmployee(int employeeID, int companyID, int grade){
        if(employeeID <= 0 || companyID <= 0 || companyID > numOfCompanies || grade < 0){
            return INVALID_INPUT;
        }

        if(allEmployees.find(employeeID)){
            return FAILURE;
        }
        try{
            allEmployees.insert(employeeID);
            shared_ptr<Company> company = allCompanies->findCompany(companyID);
            (company->companyEmployees).insert(employeeID);
            ++numOfZeroSalaryEmployees;
            gradeSumOfZeroSalaryEmployees += grade;
            ++numOfZeroSalaryCompany[companyID];
            sumOfGradesZeroSalaryCompany[companyID] += grade;
        }
        catch (AVLTree<Employee, CompareEmpByID>::AlreadyExists& e){
            return FAILURE;
        }
        catch (...){
            return ALLOCATION_ERROR;
        }
        return SUCCESS;
    }

    ////done
    StatusType RemoveEmployee(int employeeID){
        if(employeeID <= 0){
            return INVALID_INPUT;
        }
        //check if there is an employee with id = employeeID
        if(allEmployees.find(employeeID)){
            return FAILURE;
        }
        try{
            ////search employee
            shared_ptr<Employee> tmp = shared_ptr<Employee>(new Employee(employeeID, 0, 0, nullptr));
            shared_ptr<Employee> toRemove = allEmployees.findEmployee(tmp);
            shared_ptr<Company> company = toRemove->Company;
            ////need to remove from hash + rank Company
            //from hash of company
            (company->companyEmployees).remove(toRemove);
            //from hash of structure
            allEmployees.remove(toRemove);
            //check if exists in rankTree with salary = 0
            if(toRemove->salary == 0){
                sumOfGradesZeroSalaryCompany[company->id] -= toRemove->grade;
                numOfZeroSalaryCompany[company->id]--;
                gradeSumOfZeroSalaryEmployees -= toRemove->grade;
                numOfZeroSalaryEmployees--;
            }else{//salary > 0, remove from rank
                //removing from rank of company
                (company->employessWithSalary).remove(toRemove);
                //removing from rank of structure
                allEmployeesWithSalary.remove(toRemove);
            }
            ////need to remove from hash + rank structure
        }
        catch (AVLTree<Employee, CompareEmpByID>::DoesntExist& e){
            return SUCCESS;
        }
        catch (RankTree<Employee, CompareEmpByID>::DoesntExist& e){
            return SUCCESS;
        }
        catch (...){//bad alloc
            return ALLOCATION_ERROR;
        }
        return SUCCESS;
    }

    StatusType AcquireCompany(int companyID1, int companyID2, double factor){
        if(companyID1 <= 0 || companyID1 > numOfCompanies || companyID2 <= 0 || companyID2 > numOfCompanies
            || companyID1 == companyID2 || factor <= 0.0){
            return INVALID_INPUT;
        }

    }

    StatusType EmployeeSalaryIncrease(int employeeID, int salaryIncrease){
        if(employeeID <= 0 || salaryIncrease <= 0){
            return INVALID_INPUT;
        }
        if(allEmployees.find(employeeID)){
            return FAILURE;
        }

    }

    StatusType PromoteEmployee(int employeeID, int bumpGrade){
        if(employeeID <= 0){
            return INVALID_INPUT;
        }
        if(allEmployees.find(employeeID)){
            return FAILURE;
        }
    }

    StatusType SumOfBumpGradeBetweenTopWorkersByGroup(int companyID, int m, void * sumBumpGrade){
        if(!sumBumpGrade || companyID > numOfCompanies || companyID < 0 || m <= 0){
            return INVALID_INPUT;
        }
        if(allEmployeesWithSalary.getSize() < m){
            return FAILURE;
        }
        if(companyID != 0 && )
    }

    StatusType AverageBumpGradeBetweenSalaryByGroup(int companyID, int lowerSalary, int higherSalary, void * averageBumpGrade);

    ////done
    StatusType CompanyValue(int companyID, void * standing){
        if(!standing || companyID <= 0 || companyID > numOfCompanies){
            return INVALID_INPUT;
        }
        (*standing) = allCompanies->getTotalExtraForCompany(companyID);
        return SUCCESS;
    }

};

#endif //WET2_EmployeeManager_H
