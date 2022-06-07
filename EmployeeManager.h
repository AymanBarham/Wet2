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
public:
    EmployeeManager(int k): allCompanies(new UnionFindCompanies(k)), numOfCompanies(k){}
    ~EmployeeManager(){
        delete allCompanies;
    }

    //maybe there is no need to do try and catch

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
            ////removing from rank tree of the data structure
            shared_ptr<Employee> toRemove = shared_ptr<Company>(new Employee(employeeID, 0, 0, nullptr));
            shared_ptr<Employee> foundToRemove = allEmployeesWithSalary.find(toRemove);
            if(foundToRemove){
                allEmployeesWithSalary.remove(foundToRemove);
            }
            ////removing from rank tree of the company of the employee
            shared_ptr<Employee> empToRemoveFromCompany = allEmployees.findEmployee(toRemove);
            if(empToRemoveFromCompany){
                shared_ptr<Company> company = allCompanies->findCompany(empToRemoveFromCompany->company->id);
                shared_ptr<Employee> foundToRemoveInCompany = company->employeesWithSalary.find(empToRemoveFromCompany);
                if(foundToRemoveInCompany){
                    company->employeesWithSalary.remove(find);
                }
                ////remove from the hash of the company
                company->companyEmployees.remove(empToRemoveFromCompany);
            }
            ////removing from hash of the data structure
            allEmployees.remove(employeeID);
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
