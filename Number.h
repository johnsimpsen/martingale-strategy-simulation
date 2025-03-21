//
// Created by johnsimpsen on 3/15/2025.
//

#ifndef NUMBER_H
#define NUMBER_H

#include <string>

class Number {

private:
    std::string value;
    std::string color;

public:
    Number(std::string v, std::string c) {
        value = v;
        color = c;
    }

    //Accessors
    std::string getValue() const {return value;}
    std::string getColor() const {return color;}

    //Overloaded operators
    friend std::ostream& operator<<(std::ostream &os, const Number& n);
};



#endif //NUMBER_H
