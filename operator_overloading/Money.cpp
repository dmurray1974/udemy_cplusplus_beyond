//
// Created by Darren Murray on 18/08/2026.
//

#include "Money.h"

Money::Money(int total)
    : dollars(total/100), cents(total%100) {
}

Money::Money(int dollars, int cents)
    : dollars(dollars), cents(cents) {
}

bool Money::operator==(const Money &rhs) const {
    return dollars == rhs.dollars && cents == rhs.cents;
}

bool Money::operator!=(const Money &rhs) const {
    return !(*this == rhs);
}