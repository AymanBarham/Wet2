

#ifndef WET2_HASHTABLE_H
#define WET2_HASHTABLE_H
#include "RankTree.h"
#include "DynamicArray.h"
#include <iostream>
#include <memory>
#include "Employee.h"
#include "AVLTree.h"
#include "CompareEmpByID.h"

using std::string;
using std::shared_ptr;

class Employee;

class HashTable {
    DynamicArray<AVLTree<Employee, CompareEmpByID>> array;
    int arraySize;
    int numberOfElements;
public:
    HashTable() : array(), arraySize(INIT_SIZE), numberOfElements(0) {}
    ~HashTable() = default;

    unsigned int hash(shared_ptr<Employee> emp) {
        return emp->id % arraySize;
    }

    void insert(shared_ptr<Employee> to_add) {
        numberOfElements++;
        array[hash(to_add)].insert(to_add);

        if (numberOfElements >= arraySize) {
            rehash();
        }
    }

    void remove(shared_ptr<Employee> to_remove) {
        numberOfElements--;
        array[hash(to_remove)].remove(to_remove);
        if((double)numberOfElements <= (double)((arraySize) / 4)){
            rehashDown();
        }
    }

    bool find(int id) {
        shared_ptr<Employee> toFind = shared_ptr<Employee>(new Employee(id, 0, 0, nullptr));

        return array[hash(toFind)].find(toFind) != nullptr;
    }

    bool find(shared_ptr<Employee> to_find) {
        return array[hash(to_find)].find(to_find) != nullptr;
    }

    shared_ptr<Employee> findEmployee(shared_ptr<Employee> to_find){
        return array[hash(to_find)].find(to_find);
    }

    void rehash() {
        DynamicArray<AVLTree<Employee, CompareEmpByID>> newArray(arraySize * 2);
        int oldSize = arraySize;
        arraySize = 2 * arraySize;
        try{
            for (int i = 0; i < oldSize; ++i) {
                for (AVLTree<Employee, CompareEmpByID>::AVLIter it = array[i].begin(); it != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(*it);
                }
            }
        } catch (...){
            arraySize = oldSize;
            throw;
        }
        this->array.~DynamicArray();
        this->array = newArray;
        newArray.array = nullptr;
    }

    void rehashDown() {
        DynamicArray<AVLTree<Employee, CompareEmpByID>> newArray(arraySize / 2);
        int oldSize = arraySize;
        arraySize = arraySize / 2;
        try{
            for (int i = 0; i < oldSize; ++i) {
                for (AVLTree<Employee, CompareEmpByID>::AVLIter it = array[i].begin(); it != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(*it);
                }
            }
        } catch (...){
            arraySize = oldSize;
            throw;
        }
        (this->array).~DynamicArray();
        this->array = newArray;
        newArray.array = nullptr;

    }

    void merge(const HashTable& toMergeFrom) {
        DynamicArray<AVLTree<Employee, CompareEmpByID>> newArray((arraySize + toMergeFrom.arraySize) * 2);
        int oldSize = arraySize;
        int toMergeSize = toMergeFrom.arraySize;
        arraySize = (arraySize + toMergeFrom.arraySize) * 2;
        try{
            for (int i = 0; i < oldSize; ++i) {
                for (AVLTree<Employee, CompareEmpByID>::AVLIter it = array[i].begin(); it != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(*it);
                }
            }
            for (int i = 0; i < toMergeSize; ++i) {
                for (AVLTree<Employee, CompareEmpByID>::AVLIter it = array[i].begin(); it != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(*it);
                }
            }
        } catch (...){
            arraySize = oldSize;
            throw;
        }
        (this->array).~DynamicArray();
        this->array = newArray;
        newArray.array = nullptr;
    }

};



#endif //WET2_HASHTABLE_H
