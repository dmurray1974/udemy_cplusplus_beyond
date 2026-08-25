//
// Created by Darren Murray on 25/08/2026.
//
#include <iostream>
#include "I_Printable.h"

std::ostream& operator<<(std::ostream& os, const I_Printable& obj) {
    obj.print(os);
    return os;
}
