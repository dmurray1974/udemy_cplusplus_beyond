#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
private:
    std::string name;
    int age;
public:
    // constructors
    Person(std::string name, int age) : name(name), age(age) {};
    Person(const Person& p) : name(p.name), age(p.age) {};

    // Destructors
    ~Person() = default;

    //Getters // Setters
    std::string getName() const { return name; }
    void setName(std::string name) { this->name = name; }

    int getAge() const { return age; }
    void setAge(int age) { this->age = age; }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "[Person: " << p.getName() << ":" << p.getAge() << "]";
    return os;
}


void test1() {
    std::cout << "========================= Test1() =========================" << std::endl;

    [] () { std::cout << "Hello World!" << std::endl; }();
    [] (int x) { std::cout << x << std::endl; }(100);
    [] (int x, int y) { std::cout << x + y << std::endl; }(1000, 2000);
}

void test2() {
    std::cout << "========================== Test2() ===========================" << std::endl;
    auto l1 = []() { std::cout << "Hello World!" << std::endl; };
    l1();

    int num1 {100};
    int num2 {200};

    auto l2 = [](int x, int y) {std::cout << x + y << std::endl; };
    l2(10,20);
    l2(num1, num2);

    auto l3 = [](int &x, int y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
        x = 1000;
        y = 2000;
    };

    l3(num1, num2);
    std::cout << "num1: " << num1 << " num2: " << num2 << std::endl;
}

void test3() {
    std::cout << "=========================== Test3() =============================" << std::endl;
    Person stooge {"Larry", 18};
    std::cout << stooge << std::endl;

    auto l4 = [] (Person p) {
        std::cout << p << std::endl;
    };
    l4(stooge);

    auto l5 = [] (const Person &p) {
        std::cout << p << std::endl;
    };
    l5(stooge);

    auto l6 = [] (Person &p) {
        p.setName("Frank");
        p.setAge(25);
        std::cout << p << std::endl;
    };
    l6(stooge);

    std::cout << stooge << std::endl;

}

void filter_vector(const std::vector<int> &vec, std::function<bool(int)> func) {
    std::cout << "[ ";
    for (auto x : vec) {
        if (func(x)) {
            std::cout << x << " ";
        }
    }
    std::cout << "]" << std::endl;
}


void test4() {
    std::cout << "========================== Test4() =============================" << std::endl;

    std::vector<int> nums {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    filter_vector(nums, [](int x) {return x>50; });
    filter_vector(nums, [](int x) {return x<=30; });
    filter_vector(nums, [](int x) {return x >= 30 && x <= 60; });

}

auto make_lambda() {
    return []() {std::cout << "This lambda was made using the make_lambda function!";};
}

void test5() {
    std::cout << "========================== Test5() =============================" << std::endl;

    auto l5 = make_lambda();

    l5();
}

void test6() {
    std::cout << "========================== Test6() ===============================" << std::endl;
    auto l6 = [] (auto x, auto y) {
        std::cout << "x: " << x << " y: " << y << std::endl;
    };

    l6(10,20);
    l6(100.3, 200);
    l6(12.5,15.54);

    l6(Person("Larry", 18), Person("Curly", 22));
}

void test7() {
    std::cout << "========================== Test7() ===============================" << std::endl;

    std::vector<Person> stooges {
      Person{"Larry", 18},
      Person{"Moe", 30},
      Person{"Curly", 25}
    };

    std::cout << "Original Order:" << std::endl;
    std::for_each(begin(stooges),end(stooges),[](const Person &p) {
        std::cout << p << std::endl;
    });
    std::cout << std::endl;

    std::cout << "Order By Name:" << std::endl;
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
        return p1.getName() < p2.getName();
    });

    std::for_each(begin(stooges),end(stooges),[](const Person &p) {
        std::cout << p << std::endl;
    });

    std::cout << std::endl;

    std::cout << "Order By Age:" << std::endl;
    std::sort(begin(stooges), end(stooges), [](const Person &p1, const Person &p2) {
    return p1.getAge() < p2.getAge();
});

    std::for_each(begin(stooges),end(stooges),[](const Person &p) {
        std::cout << p << std::endl;
    });
}

int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();

    return 0;
}