#include <iostream>
#include <set>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    std::string name;
    int age;
public:

    // Constructors
    Person() : name("Unknown"), age(0) {}
    Person(std::string name, int age) : name(name), age(age) {}

    // Overloaded operations
    bool operator<(const Person& p) const {
        return this->age < p.age;
    }
    bool operator==(const Person& p) const {
        return (this->name == p.name && this->age == p.age);
    }
};

// Overloaded operator <<
std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << p.name << ":" << p.age;
    return os;
}


template <typename T>
void display(const std::set<T> &l) {
    std::cout << '[';
    for (auto it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << ", ";
    }
    std::cout << ']' << std::endl;
}

void test1() {
    //Sets
    std::cout << "\n============== Test1() =======================" << std::endl;
    std::set<int> s1 {1, 4, 3, 5, 2};
    display(s1);

    s1 = {1,2,3,1,1,2,2,3,3,4,5};
    display(s1);

    s1.insert(0);
    s1.insert(10);
    display(s1);

    if (s1.count(10)) {
        std::cout << "s1 count 10: " << s1.count(10) << std::endl;
    } else {
        std::cout << "s1 not count 10: " << s1.count(10) << std::endl;
    }

    auto it = s1.find(5);
    if (it != s1.end()) {
        std::cout << "Found: " << *it << std::endl;
    }

    s1.clear();
}

int main() {
    test1();
    return 0;
}