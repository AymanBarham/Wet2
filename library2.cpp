
#include "library2.h"
#include "EmployeeManager.h"



void *Init(int k){
    if(k <= 0){
        return NULL;
    }
    EmployeeManager* EM = new EmployeeManager((long)k);
    return EM;
}

StatusType AddEmployee(void *DS, int employeeID, int companyID, int grade) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AddEmployee((long)employeeID, (long)companyID,(long) grade);
}

StatusType RemoveEmployee(void *DS, int employeeID) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->RemoveEmployee((long)employeeID);
}

StatusType AcquireCompany(void *DS, int companyID1, int companyID2, double factor) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AcquireCompany((long)companyID1,(long) companyID2, factor);
}

StatusType EmployeeSalaryIncrease(void *DS, int employeeID, int salaryIncrease) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->EmployeeSalaryIncrease((long)employeeID, (long)salaryIncrease);
}

StatusType PromoteEmployee(void *DS, int employeeID, int bumpGrade) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->PromoteEmployee((long)employeeID,(long) bumpGrade);
}

// no polonger
StatusType SumOfBumpGradeBetweenTopWorkersByGroup(void *DS, int companyID, int m) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->SumOfBumpGradeBetweenTopWorkersByGroup((long)companyID, (long)m);
}
// no polonger
StatusType AverageBumpGradeBetweenSalaryByGroup(void *DS, int companyID, int lowerSalary, int higherSalary) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AverageBumpGradeBetweenSalaryByGroup((long)companyID,(long) lowerSalary,(long) higherSalary);
}

// no polonger
StatusType CompanyValue(void *DS, int companyID){
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->CompanyValue((long)companyID);
}

/*
 * 20 polong Bonus function:
StatusType BumpGradeToEmployees(void *DS, int lowerSalary, int higherSalary, int bumpGrade);
 */

void Quit(void** DS){
    delete (EmployeeManager*)(*DS);
    *DS = nullptr;
}


