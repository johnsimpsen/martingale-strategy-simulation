//
// Created by johnsimpsen on 3/15/2025.
//

#ifndef WHEEL_H
#define WHEEL_H

#include <iostream>
#include <string>
#include <random>

#include "Number.h"



class Wheel {

private:
    std::vector<Number*> nums;

public:

    //Constructor
    Wheel(std::vector<Number*> n) {
        nums = n;
    }

    //Destructor
    ~Wheel() {
        for (Number* n : nums) {
            delete n;
        }
        nums.clear();
    }

    //Functions
    void printNums() const;
    Number* spin() const;


};



#endif //WHEEL_H
