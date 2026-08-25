//
// Created by Darren Murray on 25/08/2026.
//

#ifndef SEC16_CHALLENGE_I_PRINTABLE_H
#define SEC16_CHALLENGE_I_PRINTABLE_H

#include <iostream>

class I_Printable {
    friend std::ostream& operator<<(std::ostream& os, const I_Printable& obj);
public:
    virtual void print(std::ostream& os) const =0;
    virtual ~I_Printable() = default;
};
#endif //SEC16_CHALLENGE_I_PRINTABLE_H