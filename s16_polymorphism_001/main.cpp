#include <iostream>
#include <memory>

class Base {
public:
    void say_hello() const {
        std::cout << "Hello - I am a Base Class object" << std::endl;
    }
};

class Derived : public Base {
public:
    void say_hello() const {
        std::cout << "Hello - I am a Derived Class object" << std::endl;
    }
};


// expects Base object bt REFERENCE
void greetings(const Base &obj) {
    std::cout << "Greetings: ";
    obj.say_hello();
}


int main() {
    Base b;
    b.say_hello();

    Derived d;
    d.say_hello();

    greetings(b);
    greetings(d);

    Base *ptr = new Derived();
    ptr->say_hello();

    // Smart Pointer
    std::unique_ptr<Base> ptr1 = std::make_unique<Derived>();
    ptr1->say_hello();


    delete ptr;

    return 0;
}