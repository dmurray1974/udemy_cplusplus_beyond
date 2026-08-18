//
// Created by Darren Murray on 17/08/2026.
//

#ifndef OPERATOR_OVERLOADING_MYSTRING_H
#define OPERATOR_OVERLOADING_MYSTRING_H
#include <iosfwd>

class Mystring {

    friend std::ostream& operator<<(std::ostream& os, const Mystring& rhs);
    friend std::istream& operator>>(std::istream& is, Mystring& rhs);
private:
    char *str;

public:
    Mystring();     //No-Args Constructor
    Mystring(const char *s);   // 1 Arg Constructor
    Mystring(const Mystring &source);   // Copy constructor
    ~Mystring();            // Destructor

    Mystring &operator=(const Mystring &rhs);   // Assignment operator overload (Copy)

    Mystring &operator=(Mystring &&rhs);   // Assignment operator overload (Move)

    Mystring operator-() const;

    bool operator==(const Mystring &rhs) const;
    Mystring operator+(const Mystring &rhs) const;

    void display() const;
    int get_length() const;
    const char *get_str() const;
};

#endif //OPERATOR_OVERLOADING_MYSTRING_H