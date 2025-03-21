//
// Created by johnsimpsen on 3/15/2025.
//

#include "Wheel.h"

void Wheel::printNums() const {
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i]->getValue() << " ";
    }
}

Number* Wheel::spin() const {
    std::random_device rd;
    int seed = rd(); //Generate random seed
    srand(seed); //Set seed
    int ran = rand() % nums.size(); //Generate random number [0-37]

    return nums[ran];
}