//
// Created by Darren Murray on 17/08/2026.
//

#include "Mystring.h"

#include <cstring>
#include <iostream>
#include <ostream>

// No-Args Constructor
Mystring::Mystring()
    : str{nullptr} {
    std::cout << ">>Constructing Mystring NoArgs" << std::endl;
    str = new char[1];
    *str = '\0';
}

// Overloaded Constructor
Mystring::Mystring(const char *s)
    : str {nullptr} {
    std::cout << ">>Overloaded Constructor: " << s << std::endl;
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}


// Copy constructor
Mystring::Mystring(const Mystring &source)
    : str {nullptr} {
    std::cout << ">>Copy Constructor: " << std::endl;
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

Mystring &Mystring::operator=(const Mystring &rhs) {
    std::cout << ">>[Copy]Mystring::operator=(const Mystring &rhs): " << rhs.str << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(str, rhs.str);
    return *this;
}

Mystring &Mystring::operator=(Mystring &&rhs) {
    std::cout << ">>[Move]Mystring::operator=(const Mystring &rhs): " << rhs.str << std::endl;
    if (this == &rhs) {
        return *this;
    }
    delete [] this->str;
    this->str = rhs.str;

    rhs.str = nullptr;

    return *this;
}

Mystring Mystring::operator-() const {
    std::cout << ">>Mystring::operator-(): " << this->str << std::endl;
    char *buff = new char[std::strlen(str) + 1];
    std::strcpy(buff, str);
    for (size_t i {0}; i<std::strlen(buff); i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete [] buff;
    return temp;
}

bool Mystring::operator==(const Mystring &rhs) const {
    std::cout << ">>Mystring::operator==(const Mystring &rhs): " << rhs.str << std::endl;
    if (std::strcmp(this->str, rhs.str) == 0) {
        return true;
    }
    return false;
}

Mystring Mystring::operator+(const Mystring &rhs) const {
    std::cout << ">>Mystring::operator+(const Mystring &rhs): " << rhs.str << std::endl;

    size_t buff_size = std::strlen(this->str) + std::strlen(rhs.str) + 1;
    char *buff = new char[buff_size];
    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete [] buff;

    return temp;
}


// Desctructor
Mystring::~Mystring() {
    std::cout << ">>Mystring::~Mystring()" << std::endl;
    delete [] str;
}

void Mystring::display() const {
    std::cout << str << " : " << get_length() <<  std::endl;
}

int Mystring::get_length() const {
    return std::strlen(str);
}

const char *Mystring::get_str() const {
    return str;

}

//Overloaded Insertion <<
std::ostream& operator<<(std::ostream& os, const Mystring& rhs) {
    return os << rhs.str;
}

//Overload extraction >>
/*
 * This example from the course is pre c++20 example, had to change as using c++20
 * Leaving it here as an example
 *
std::istream& operator>>(std::istream& is, Mystring& rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = Mystring {buff};
    delete[] buff;
    return is;
}
*/

std::istream& operator>>(std::istream& is, Mystring& rhs) {
    char *buff = new char[1000];
    is.get(buff, 1000);
    rhs = Mystring{buff};
    delete[] buff;
    return is;
}