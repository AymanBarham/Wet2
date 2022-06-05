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
        double value;
        int mainCompanyID;
    };
public:
    void union(Card& card1, Card& card2)
    {

    }



};

#endif //AVLTREE_H_UNIONFINDCOMPANIES_H
