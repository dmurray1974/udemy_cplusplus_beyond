#include <iostream>

using namespace std;

class Base {
public:
    int value {0};
    int a {0};
    Base() : value{0} {
        cout << "Base Constructor - No-Args" << endl;
    }
    Base(int x) : value{x} {
        cout << "Base Constructor with Arg " << value << endl;
    }

    // Copy Constructor
    Base(const Base& other) : value{other.value} {
        cout << "Base Copy Constructor - No-Args" << endl;
    }

    // Overloaded Assignment Operator
    Base &operator=(const Base& rhs) {
        cout << "Base Assignment operator= - No-Args" << endl;
        if (this == &rhs) {
            return *this;
        }
        value = rhs.value;
        return *this;
    }
    ~Base() {
        cout << "Base Desstructor" << endl;
    }
    void display() {
        cout << "a: " << a << ", b: " << b <<  ", c: " << c << endl;
    }
protected:
    int b {0};
private:
    int c {0};
};

class Derived : public Base {
    //using Base::Base;
    // a will be Public
    // b will be protected
    // c will be Unaccessible
public:
    int doubled_value;
    void access_base_members() {
        a = 100;    //OK
        b = 200;    //OK
 //       c = 300;    // Not Accessible
    }
    Derived() : Base{}, doubled_value{100} {
        cout << "Derived Constructor - No-Args" << endl;
    }
    Derived(int x) : Base{x}, doubled_value{x*2} {
        cout << "Derived Constructor with Value : " << doubled_value << endl;
    }
    Derived(const Derived &other)
    : Base(other), doubled_value{other.doubled_value} {
        cout << "Derived Copy Constructor - No-Args" << endl;
    }

    Derived& operator=(const Derived &rhs) {
        cout << "Derived Assignment operator= - No-Args" << endl;
        if (this == &rhs) {
            return *this;
        }
        Base::operator=(rhs);
        doubled_value = rhs.doubled_value;
        return *this;
    }
    ~Derived() {
        cout << "Derived Destructor" << endl;
    }
};

int main() {
    std::cout << "========Base Member" << std::endl;
    Base b {100};
    Base b1 {b};
    b = b1;
   // base.a = 100;    //OK
   // base.b = 200;   //Compiler Error, not available publically
   // base.c = 300;   //Compiler Error, not available publically

    std::cout << endl << "========Derived Member" << std::endl;
    Derived d {100};
    Derived d1 {12};
    d = d1;
 //   d.a = 100;  //OK
//    d.b = 200;  //Error
//    d.c = 300;  //Error


    return 0;
}