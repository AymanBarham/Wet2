//
// Created by omarz on 04/06/2022.
//

#ifndef AVLTREE_H_UNIONFINDCOMPANIES_H
#define AVLTREE_H_UNIONFINDCOMPANIES_H
#include "Company.h"
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::weak_ptr;

class UnionFindCompanies
{
private:

    struct UnionTreeNode {
        UnionTreeNode* father;
        shared_ptr<Company> company;
        double valueExtra;
        weak_ptr<Company> mainCompany;
        long size;
    };

    UnionTreeNode** members;
    long k;

public:
    explicit UnionFindCompanies(long k): members(new UnionTreeNode*[k + 1]), k(k){
        for (long i = 1; i <= k; ++i) {
            members[i] = new UnionTreeNode();
            members[i]->father = nullptr;
            members[i]->company = shared_ptr<Company>(new Company(i, i));
            members[i]->valueExtra = 0;
            members[i]->mainCompany = members[i]->company;
            members[i]->size = 1;
        }
    }

    ~UnionFindCompanies(){
        for (long i = 1; i <=k ; ++i) {
            members[i]->company.reset();
            delete members[i];
        }
        delete[] members;
    }

    void updateExtraValue(UnionTreeNode* toUpdate, UnionTreeNode* root)
    {
        if(toUpdate->father == nullptr || toUpdate == root)
        {
            return;
        }
        double sumExtra = toUpdate->valueExtra;
        UnionTreeNode* firstNode = toUpdate;
        while(toUpdate->father != root){
            toUpdate = toUpdate->father;
            sumExtra += toUpdate->valueExtra;
        }
        toUpdate = firstNode;
        toUpdate->valueExtra = sumExtra;
    }

    //returns the root of toFind in the uptree
    UnionTreeNode* find(UnionTreeNode* toFind) {
        if(toFind->father == nullptr)
        {
            return toFind;
        }
        UnionTreeNode* root = find(toFind->father);
        updateExtraValue(toFind, root);
        toFind->father = root;
        return root;
    }

    //returns the main company in the current group
    shared_ptr<Company> findCompany(long id) {
        UnionTreeNode* toFind = find(members[id]);
        return toFind->mainCompany.lock();
    }

    double getTotalExtraValue(UnionTreeNode* toFind){
        double totalValue = 0;
        while (toFind != nullptr){
            totalValue += toFind->valueExtra;
            toFind = toFind->father;
        }
        return totalValue;
    }

    double getTotalExtraForCompany(long companyID){
        return getTotalExtraValue(members[companyID]);
    }

    //return the main company of the current group
    shared_ptr<Company> unionCompanies(long acquirerID, long targetID, double factor)
    {
        UnionTreeNode* acquirer = find(members[acquirerID]);
        UnionTreeNode* target = find(members[targetID]);
        if (acquirer == target) {
            return acquirer->mainCompany.lock();
        }
        shared_ptr<Company> acquirerMain = findCompany(acquirerID);
        shared_ptr<Company> targetMain = findCompany(targetID);

        if(acquirer->size >= target->size){
            ////update the size of the group after the union
            acquirer->size += target->size;
            ////update the value Extra field for the acquirer
            acquirer->valueExtra += (factor * (targetMain->value + getTotalExtraValue(members[targetMain->id])));
            ////update the value Extra field for the target
            target->valueExtra -= (acquirer->valueExtra);
            target->father = acquirer;
        }else{
            target->size += acquirer->size;
            acquirer->valueExtra += ((factor * (targetMain->value + getTotalExtraValue(members[targetMain->id])) - target->valueExtra));
            acquirer->father = target;
        }
        ////merge the trees of the workers
        (acquirerMain->employeesWithSalary).merge(targetMain->employeesWithSalary);
        ////merge the hashes of the workers
        (acquirerMain->companyEmployees).merge(targetMain->companyEmployees);
        ////update the main company
        target->mainCompany = acquirer->mainCompany;


        for (RankTree<Employee, CompareEmpBySalary>::AVLIter it = acquirer->mainCompany.lock()->employeesWithSalary.begin();
                it != acquirer->mainCompany.lock()->employeesWithSalary.end(); ++it) {
            (*it)->company = acquirer->mainCompany;
        }


        return  acquirer->mainCompany.lock();
    }

};

#endif //AVLTREE_H_UNIONFINDCOMPANIES_H
