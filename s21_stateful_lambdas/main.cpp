#include <iostream>
#include <vector>
#include <algorithm>

int global_x {1000};


// Capture by Value
void test1() {
    std::cout << "================ Test1() ===============" << std::endl;

    int local_x {100};

    auto l = [local_x] () {
        std::cout << "Local: " << local_x << std::endl;
        std::cout << "Global: " << global_x << std::endl;
    };
    l();
}

// Capture by Value - Mutable ( can modify the captured value locally in the code
void test2() {
    std::cout << "================ Test2() ==============" << std::endl;

    int x {100};

    auto l = [x] () mutable {
        x += 100;
        std::cout << "x: " << x << std::endl;
    };

    l();
    std::cout << "1: " << x << std::endl;

    l();
    std::cout << "2: " << x << std::endl;
}


// Capture by Reference
void test3() {
    std::cout << "================ Test3() ==============" << std::endl;

    int x {100};

    auto l = [&x] () mutable {
        x += 100;
        std::cout << "x: " << x << std::endl;
    };

    l();
    std::cout << "1: " << x << std::endl;
}

// Default Capture by value mutable ( Copy )
void test4() {
    std::cout << "================ Test4() ==============" << std::endl;
    int x {100};
    int y {200};
    int z {300};

    auto l = [=] () mutable {
        x += 100;
        y += 200;
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
    };

    l();

    std::cout << std::endl ;
    std::cout << "x1: " << x << std::endl;
    std::cout << "y1: " << y << std::endl;

}

// Default Capture by reference
void test5() {
    std::cout << "================ Test5() ==============" << std::endl;
    int x {100};
    int y {200};
    int z {300};

    auto l = [&] () {
        x += 101;
        y += 102;
        z += 103;
        std::cout << "x0: " << x << std::endl;
        std::cout << "y0: " << y << std::endl;
        std::cout << "z0: " << z << std::endl;
    };

    l();
    std::cout << std::endl ;
    std::cout << "x1: " << x << std::endl;
    std::cout << "y1: " << y << std::endl;
    std::cout << "z1: " << z << std::endl;

}

// Default Capture by value, capture y by Reference
void test6() {
    std::cout << "================ Test6() ==============" << std::endl;

    int x {100};
    int y {200};
    int z {300};

    auto l = [=, &y] () mutable {
        x += 100;
        y += 200;
        z += 300;
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };

    l();

    std::cout << std::endl ;
    std::cout << "x1: " << x << std::endl;
    std::cout << "y1: " << y << std::endl;
    std::cout << "z1: " << z << std::endl;
}

// Default capture by reference, capture X & Z by value
// Equiv to test6()
void test7() {
    std::cout << "================ Test7() ==============" << std::endl;
    int x {100};
    int y {200};
    int z {300};
    auto l = [&, x, z] () mutable {
        x += 100;
        y += 200;
        z += 300;
        std::cout << "x: " << x << std::endl;
        std::cout << "y: " << y << std::endl;
        std::cout << "z: " << z << std::endl;
    };

    l();
    std::cout << std::endl ;
    std::cout << "x1: " << x << std::endl;
    std::cout << "y1: " << y << std::endl;
    std::cout << "z1: " << z << std::endl;
}

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
private:
    std::string name;
    int age;
public:

    // Constructors
    Person() = default;
    Person(std::string name, int age) : name(name), age(age) {}
    Person(const Person& p) = default;

    // Destructor
    ~Person() = default;

    // Getters
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // Setters
    void setAge(int age) { this->age = age; }
    void setName(std::string name) { this->name = name; }

    auto change_person1() {
        return [this] (std::string new_name, int new_age) {
            name = new_name; age = new_age;
        };
    }

 /*   auto change_person2() {
        return [=]  (std::string new_name, int new_age) {
            name = new_name;
            age = new_age;
        };
    }
*/
    auto change_person3() {
        return [&] (std::string new_name, int new_age) {
            name = new_name; age = new_age;
        };
    }
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
    os << "[Person: " << p.getName() << ":" << p.getAge() << "]" << std::endl;
    return os;
}

void test8() {
    std::cout << "================ Test8() ==============" << std::endl;

    Person person("Larry", 18);
    std::cout << person;

    // Preffered method [this]
    auto change_person1 = person.change_person1();
    change_person1("Moe", 30);
    std::cout << "P1: " << person << std::endl;

    // default Capture [&]
    auto change_person3 = person.change_person3();
    change_person3("Frank", 34);
    std::cout << "P3: " << person << std::endl;


}

class Lambda {
private:
    int y;
public:
    Lambda(int y) : y(y) {};

    void operator()(int x) const {
        std::cout << "Lambda1: " << x+y << std::endl;
    };
};

void test9() {
    std::cout << "================ Test9() ==============" << std::endl;

    int y {101};  // Passed as in the Lambda


    Lambda lambda1(y);
    auto lambda2 = [y] (int x) {std::cout << "Lambda2: " << x + y << std::endl; };


    lambda1(200);
    lambda2(200);
}

class People {
private:
    std::vector<Person> people;
    int max_people;
public:
    People(int max=10) : max_people(max) {};
    People(const People& p) = default;

    void add(std::string name, int age) {
        people.emplace_back(name, age);
    }

    void set_max_people(int max) {
        this->max_people = max;
    }

    int get_max_people() const {
        return max_people;
    }

    std::vector<Person> get_people(int max_age) {
        std::vector<Person> result;
        int count{0};
        std::copy_if(people.begin(),
                    people.end(),
                    std::back_inserter(result),
                    [this, &count, max_age](const Person& p) {
                        return p.getAge() >= max_age && ++count <= max_people;
                    });
        return result;
    }
};

void test10() {
    std::cout << "================ Test10() ==============" << std::endl;

    People friends;
    friends.add("John", 10);
    friends.add("Curly", 20);
    friends.add("John", 30);
    friends.add("Chevy", 40);
    friends.add("Stan", 50);

    auto result = friends.get_people(17);

    std::cout << std::endl;
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

    friends.set_max_people(3);

    result = friends.get_people(31);

    std::cout << std::endl;
    for (const auto& p : result) {
        std::cout << p << std::endl;
    }

}
int main() {

    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}