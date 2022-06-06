//
// Created by omarz on 04/06/2022.
//

#ifndef AVLTREE_H_UNIONFINDCOMPANIES_H
#define AVLTREE_H_UNIONFINDCOMPANIES_H
#include "Company.h"
#include <memory>
#include <iostream>

using std::shared_ptr;
using std::weak_tree;

class UnionFindCompanies
{
private:

    struct UnionTreeNode {
        shared_ptr<UnionTreeNode> father;
        shared_ptr<Company> company;
        double valueExtra;
        weak_ptr<Company> mainCompany;
        int size;
    };

    UnionTreeNode** members;
    int k;

public:
    explicit UnionFindCompanies(int k): members(new UnionTreeNode*[k + 1]), k(k){
        for (int i = 1; i <= k; ++i) {
            members[i] = new UnionTreeNode();
            members[i]->father = nullptr;
            members[i]->company = new Company(i, i);
            members[i]->valueExtra = 0;
            members[i]->mainCompany = members[i].company;
            members[i]->size = 1;
        }
    }
    ~UnionFindCompanies(){
        for (int i = 1; i <=k ; ++i) {
            delete members[i]->company;
            delete members[i]
        }
        delete[] members;
    }

    UnionTreeNode* find(int id) {
        return nullptr;
    }
    shared_ptr<Company> findCompany(int id) {
        return nullptr;
    }

    shared_ptr<Company> unionCompanies(int acquirerID, int targetID)
    {
        UnionTreeNode* acquirer = find(acquirerID);
        UnionTreeNode* target = find(targetID);

        if (acquirer == target) {
            return acquirer;
        }

        if (acquirer->size > target->size) {
            acquirer->size += target->size;
            target->father = acquirer;
            target->valueExtra -= acquirer->company->value;

            acquirer->mainCompany = acquirer;

        }else{
            target->size += acquirer->size;
            acquirer->father = target;
            target->mainCompany = acquirer;
        }

    }



};

#endif //AVLTREE_H_UNIONFINDCOMPANIES_H
