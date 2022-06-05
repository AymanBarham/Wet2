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

    UnionTreeNode* members;
    int k;

public:
    explicit UnionFindCompanies(int k): members(new UnionTreeNode[k + 1]), k(k){
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
        shared_ptr<Company> acquirer = findCompany(acquirerID);
        shared_ptr<Company> target = findCompany(targetID);

        if (acquirer == target) {

        }
    }



};

#endif //AVLTREE_H_UNIONFINDCOMPANIES_H
