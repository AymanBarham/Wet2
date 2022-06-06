//
// Created by omarz on 04/06/2022.
//

#ifndef AVLTREE_H_UNIONFINDCOMPANIES_H
#define AVLTREE_H_UNIONFINDCOMPANIES_H
#include "Company.h"
#include <memory>
#include <iostream>

using std::shared_ptr;

class UnionFindCompanies
{
private:

    struct UnionTreeNode {
        shared_ptr<UnionTreeNode> father;
        shared_ptr<Company> company;
        double valueExtra;
        int mainCompanyID;
    };

    UnionTreeNode** members;
    int k;

public:
    explicit UnionFindCompanies(int k): members(new UnionTreeNode*[k + 1]), k(k){
        for (int i = 1; i <= k; ++i) {
            members[i].company = new Company(i, i);
            members[i].father = nullptr;
            members[i].valueExtra = 0;
            members[i].mainCompanyID = i;
        }
    }

    shared_ptr<Company> findCompany(int id) {
        return nullptr;
    }

    void unionCompanies(int acquirerID, int targetID)
    {
        UnionTreeNode* acquirer = find(acquirerID);
        UnionTreeNode* target = find(targetID);

        if (acquirer == target) {

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
