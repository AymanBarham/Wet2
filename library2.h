/****************************************************************************/
/*                                                                          */
/* This file contains the longerface functions                               */
/* you should use for the wet ex 2                                          */
/*                                                                          */
/****************************************************************************/

/****************************************************************************/
/*                                                                          */
/* File Name : library2.h                                                   */
/*                                                                          */
/****************************************************************************/

#ifndef _234218_WET2
#define _234218_WET2

#ifdef __cplusplus
extern "C" {
#endif

/* Return Values
 * ----------------------------------- */
typedef enum {
    SUCCESS = 0,
    FAILURE = -1,
    ALLOCATION_ERROR = -2,
    INVALID_INPUT = -3
} StatusType;


void *Init(long k);

StatusType AddEmployee(void *DS, long employeeID, long companyID, long grade);

StatusType RemoveEmployee(void *DS, long employeeID);

StatusType AcquireCompany(void *DS, long companyID1, long companyID2, double factor);

StatusType EmployeeSalaryIncrease(void *DS, long employeeID, long salaryIncrease);

StatusType PromoteEmployee(void *DS, long employeeID, long bumpGrade);

StatusType SumOfBumpGradeBetweenTopWorkersByGroup(void *DS, long companyID, long m);

StatusType AverageBumpGradeBetweenSalaryByGroup(void *DS, long companyID, long lowerSalary, long higherSalary);

StatusType CompanyValue(void *DS, long companyID);

/*
 * 20 polong Bonus function:
StatusType BumpGradeToEmployees(void *DS, long lowerSalary, long higherSalary, long bumpGrade);
 */

void Quit(void** DS);

#ifdef __cplusplus
}
#endif

#endif    /*_234218_WET2 */