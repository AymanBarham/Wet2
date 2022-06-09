
#include "library2.h"
#include "EmployeeManager.h"



void *Init(int k){
    if(k <= 0){
        return NULL;
    }
    EmployeeManager* EM = new EmployeeManager(k);
    return EM;
}

StatusType AddEmployee(void *DS, int employeeID, int companyID, int grade) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AddEmployee(employeeID, companyID, grade);
}

StatusType RemoveEmployee(void *DS, int employeeID) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->RemoveEmployee(employeeID);
}

StatusType AcquireCompany(void *DS, int companyID1, int companyID2, double factor) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AcquireCompany(companyID1, companyID2, factor);
}

StatusType EmployeeSalaryIncrease(void *DS, int employeeID, int salaryIncrease) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->EmployeeSalaryIncrease(employeeID, salaryIncrease);
}

StatusType PromoteEmployee(void *DS, int employeeID, int bumpGrade) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->PromoteEmployee(employeeID, bumpGrade);
}

// no pointer
StatusType SumOfBumpGradeBetweenTopWorkersByGroup(void *DS, int companyID, int m) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->SumOfBumpGradeBetweenTopWorkersByGroup(companyID, m);
}
// no pointer
StatusType AverageBumpGradeBetweenSalaryByGroup(void *DS, int companyID, int lowerSalary, int higherSalary) {
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->AverageBumpGradeBetweenSalaryByGroup(companyID, lowerSalary, higherSalary);
}

// no pointer
StatusType CompanyValue(void *DS, int companyID){
    if (!DS) {
        return INVALID_INPUT;
    }
    return ((EmployeeManager*)DS)->CompanyValue(companyID);
}

/*
 * 20 point Bonus function:
StatusType BumpGradeToEmployees(void *DS, int lowerSalary, int higherSalary, int bumpGrade);
 */

void Quit(void** DS){
    delete (EmployeeManager*)(*DS);
    *DS = nullptr;
}


