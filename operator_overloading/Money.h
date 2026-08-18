//
// Created by Darren Murray on 18/08/2026.
//

#ifndef OPERATOR_OVERLOADING_MONEY_H
#define OPERATOR_OVERLOADING_MONEY_H

#include <iostream>

class Money {
    int dollars;
    int cents;
public:
    bool operator==(const Money &rhs) const;
    bool operator!=(const Money &rhs) const;

    Money(int dollars, int cents);
    Money(int total);
};


#endif //OPERATOR_OVERLOADING_MONEY_H