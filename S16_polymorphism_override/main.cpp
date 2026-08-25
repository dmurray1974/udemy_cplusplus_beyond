#include <iostream>

class Base {
public:
    virtual void say_hello() const {
        std::cout << "Hello I am Base Class object" << std::endl;
    }
    virtual ~Base() {}
};

class Derived : public Base {
public:
    virtual void say_hello() const override {
        std::cout << "Hello I am Derived class" << std::endl;
    }
    virtual ~Derived() {}
};


int main() {
    Base *p1 = new Base();
    p1->say_hello();

    Derived *p2 = new Derived();
    p2->say_hello();

    Base *p3 = new Derived();
    p3->say_hello();


    delete p1;
    delete p2;
    delete p3;

    return 0;
}