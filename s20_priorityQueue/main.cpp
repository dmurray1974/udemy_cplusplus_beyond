#include <iostream>
#include <queue>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
    std::string name;
    int age;
public:
    //constructors
    Person() : name{"Unknown"}, age {0} {}
    Person(std::string name, int age)
        : name(name), age(age) {}

    // Overload Operators
    bool operator<(const Person& p) const {
        return this->age < p.age;
    }
    bool operator==(const Person& p) const {
        return this->name == p.name && this->age == p.age;
    }
};



template <typename T>
void display(std::priority_queue<T> pq) {
    std::cout << "[ ";
    while (!pq.empty()) {
        T item = pq.top();
        pq.pop();
        std::cout << item << ", ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "================== Test1() ===============" << std::endl;

    std::priority_queue<int> pq;
    for (int i : {3,5,7,12,23,12,4,100,0,3,5,7}) {
        pq.push(i);
    }

    std::cout << "Size: " << pq.size() << std::endl;
    std::cout << "Top: " << pq.top() << std::endl;

    display(pq);
    pq.pop();
    display(pq);
}

void test2() {
    std::cout << "================= Test2() ================" << std::endl;

    std::priority_queue<Person> pq;
    pq.push(Person("John", 12));
    pq.push(Person("Darren", 45));
    pq.push(Person("George", 478));
    pq.push(Person("Jemima", 34));
    pq.push(Person("Donna", 42));

    display(pq);


}


std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "{" << p.name << ":" << p.age << "}";

    return os;
}





int main() {
    test1();

    test2();
    return 0;
}