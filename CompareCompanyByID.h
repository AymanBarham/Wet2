//
// Created by Ayman Barham on 20/04/2022.
//

#ifndef WET1_COMPARECOMPANYBYID_H
#define WET1_COMPARECOMPANYBYID_H

#include <iostream>
#include "Company.h"
#include <memory>

using std::shared_ptr;

class CompareCompanyByID {
public:
    bool operator()(shared_ptr<Company> c1, shared_ptr<Company> c2) const {
        return c1->id < c2->id;
    }
};

#endif //WET1_COMPARECOMPANYBYID_H
