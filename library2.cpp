
#include "library2.h"
#include "EmployeeManager.h"



void *Init(long k){
    if(k <= 0){
        return NULL;
    }
    EmployeeManager* EM = new EmployeeManager(k);
    return EM;
}

StatusType AddEmployee(void *DS, long employeeID, long companyID, long grade) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AddEmployee(employeeID, companyID, grade);
}

StatusType RemoveEmployee(void *DS, long employeeID) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->RemoveEmployee(employeeID);
}

StatusType AcquireCompany(void *DS, long companyID1, long companyID2, double factor) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AcquireCompany(companyID1, companyID2, factor);
}

StatusType EmployeeSalaryIncrease(void *DS, long employeeID, long salaryIncrease) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->EmployeeSalaryIncrease(employeeID, salaryIncrease);
}

StatusType PromoteEmployee(void *DS, long employeeID, long bumpGrade) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->PromoteEmployee(employeeID, bumpGrade);
}

// no polonger
StatusType SumOfBumpGradeBetweenTopWorkersByGroup(void *DS, long companyID, long m) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->SumOfBumpGradeBetweenTopWorkersByGroup(companyID, m);
}
// no polonger
StatusType AverageBumpGradeBetweenSalaryByGroup(void *DS, long companyID, long lowerSalary, long higherSalary) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AverageBumpGradeBetweenSalaryByGroup(companyID, lowerSalary, higherSalary);
}

// no polonger
StatusType CompanyValue(void *DS, long companyID){
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->CompanyValue(companyID);
}

/*
 * 20 polong Bonus function:
StatusType BumpGradeToEmployees(void *DS, long lowerSalary, long higherSalary, long bumpGrade);
 */

void Quit(void** DS){
    delete (EmployeeManager*)(*DS);
    *DS = nullptr;
}


