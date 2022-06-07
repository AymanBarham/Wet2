

#ifndef WET2_HASHTABLE_H
#define WET2_HASHTABLE_H
#include "RankTree.h"
#include "DynamicArray.h"
#include <iostream>
#include <memory>
#include "Employee.h"
#include "AVLTree.h"

using std::string;
using std::shared_ptr;

class HashTable {
    DynamicArray<AVLTree<Employee, CompareEmpByID>> array;
    int arraySize;
    int numberOfElements;
public:
    HashTable() = default;
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

    bool find(shared_ptr<Employee> to_find) {
        return array[hash(to_find)].find(to_find);
    }

    bool findEmployee(shared_ptr<Employee> to_find){
        return array[hash(to_find)].find(to_find);
    }

    void rehash() {
        DynamicArray<AVLTree<Employee, CompareEmpByID>> newArray(arraySize * 2);
        int oldSize = arraySize;
        arraySize = 2 * arraySize;
        try{
            for (int i = 0; i < oldSize; ++i) {
                for (AVLTree<Employee, CompareEmpBYID>::AVLIter it = array[i].begin(); i != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(to_add);
                }
            }
        } catch (...){
            arraySize = oldSize;
            throw;
        }
        (this->array)->~DynamicArray();
        this->array = newArray;
        newArray = nullptr;
    }

    void rehashDown() {
        DynamicArray<AVLTree<Employee, CompareEmpByID>> newArray(arraySize / 2);
        int oldSize = arraySize;
        arraySize = arraySize / 2;
        try{
            for (int i = 0; i < oldSize; ++i) {
                for (AVLTree<Employee, CompareEmpBYID>::AVLIter it = array[i].begin(); i != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(to_add);
                }
            }
        } catch (...){
            arraySize = oldSize;
            throw;
        }
        (this->array)->~DynamicArray();
        this->array = newArray;
        newArray = nullptr;

    }

    void merge(const HashTable& toMergeFrom) {
        DynamicArray<AVLTree<Employee, CompareEmpByID>> newArray((arraySize + toMergeFrom.arraySize) * 2);
        int oldSize = arraySize;
        int toMergeSize = toMergeFrom.arraySize;
        arraySize = (arraySize + toMergeFrom.arraySize) * 2;
        try{
            for (int i = 0; i < oldSize; ++i) {
                for (AVLTree<Employee, CompareEmpBYID>::AVLIter it = array[i].begin(); i != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(to_add);
                }
            }
            for (int i = 0; i < toMergeSize; ++i) {
                for (AVLTree<Employee, CompareEmpBYID>::AVLIter it = array[i].begin(); i != array[i].end() ; ++it){
                    newArray[hash(*it)].insert(to_add);
                }
            }
        } catch (...){
            arraySize = oldSize;
            throw;
        }
        (this->array)->~DynamicArray();
        this->array = newArray;
        newArray = nullptr;
    }

};



#endif //WET2_HASHTABLE_H
