//
// Created by shani && yarden on 09/06/2020.
//


#include "doctest.h"
#include <iostream>
#include <vector>
#include "range.hpp"
#include "accumulate.hpp"
#include "filterfalse.hpp"


using namespace itertools;
using namespace std;

TEST_CASE("range") {

    vector<int> vec(100);
    for(int i=0;i<100;++i){
        vec[i] = i;
    }
    int j=0;
    for (int i: range(0,100)) {
                CHECK(i == vec[j]);
                j++;
    }
}




