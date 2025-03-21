//
// Created by johnsimpsen on 3/15/2025.
//

#include "Number.h"

#include <ostream>

std::ostream& operator<<(std::ostream &os, const Number& n) {

    return os << n.getValue() << " " << n.getColor() << std::endl;
}
