cmake_minimum_required(VERSION 3.22)
project(Wet2)

set(CMAKE_CXX_STANDARD 11)

add_executable(Wet2 RankTree.h DynamicArray.h HashTable.h Employee.h UnionFindCompanies.h EmployeeManager.h AVLTree.h CompareEmpByID.h CompareCompanyByID.h CompareEmpBySalary.h library2.cpp main2_without_bonus.cpp)
