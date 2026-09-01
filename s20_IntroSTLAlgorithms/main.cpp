#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person {
    friend std::ostream& operator<<(std::ostream& os, const Person& other);
private:
    std::string name;
    int age;
public:
    // Constructors
    Person() = default;
    Person(std::string name, int age) : name(name), age(age) {}

    // Overloaded Operators
    bool operator<(const Person& other) const {
        return this->age < other.age;
    }
    bool operator==(const Person& other) const {
        return this->name == other.name && this->age == other.age;
    }
};

void find_test_int(int number) {
    std::cout << "================= find_test_int() ===========================" << std::endl;

    std::vector<int> vec {1,2,3,4,5};
    vec.push_back(6);

    auto loc = std::find(vec.begin(), vec.end(), number);

    if ( loc != vec.end() ) {
        std::cout << "Found number: " << *loc << std::endl;
    } else {
        std::cout << "Did not find number: " << number << std::endl;
    }
}

void find_test_person() {
    std::cout << "================= find_test_Person() ===========================" << std::endl;

    std::list<Person> players {
    {"Larry", 18},
        {"Moe", 20},
        {"Moe", 22}
    };

    auto loc = std::find(players.begin(), players.end(), Person{"Moe", 22});

    if ( loc != players.end() ) {
        std::cout << "Found : " << *loc << std::endl;
    } else {
        std::cout << "Did not find : Moe" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Person& other) {
    os << other.name << " " << other.age;
    return os;
}

void count_test(int pnum) {
    std::cout << "\n================= count_test() ============================" << std::endl;

    std::vector<int> vec {1,2,3,4,5, 2, 3, 1, 1, 2, 1, 6};

    int num = std::count(vec.begin(), vec.end(), pnum);
    std::cout << "Found : " << num << " occurrences of " << pnum << std::endl;
}


void count_if_test() {
    std::cout << "\n================= count_if_test() ============================" << std::endl;

    // Count only if Value in element is EVEN
    std::vector<int> vec {1,2,3,4,5, 2, 3, 1, 1, 2, 1, 6};
    int num = std::ranges::count_if(vec,
                                    [](int elem) { return elem % 2 == 0; });
    std::cout << "Found : " << num << " Even Numbers" << std::endl;

    // Count only if Value in element is ODD
    num = std::count_if(vec.begin(), vec.end(),
        [](int elem) { return elem % 2 != 0; });
    std::cout << "Found : " << num << " Odd Numbers" << std::endl;

    // Count only if Value in element is >= 5
    num = std::count_if(vec.begin(), vec.end(),
        [](int elem) { return elem >= 5; });
    std::cout << "Found : " << num << " number Greater than or equal to 5" << std::endl;
}

void replace_test() {
    std::cout << "\n================ replace_test() ============================" << std::endl;
    std::vector<int> vec {1,2,3,4,5, 2, 3, 1, 1, 2, 1, 6};
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    std::replace(vec.begin(), vec.end(),1,100);
    for (auto elem : vec) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

void all_of_test() {
    std::cout << "\n================ all_of_test() ============================" << std::endl;
    std::vector<int> vec {1, 2, 5, 7, 9, 1, 3, 13, 19, 5};

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x>10; })) {
        std::cout << "All Elements are > 10" << std::endl;
    } else {
        std::cout << "Not ALL Elements are > 10" << std::endl;
    }

    if (std::all_of(vec.begin(), vec.end(), [](int x) {return x < 20; })) {
        std::cout << "All Elements are < 20" << std::endl;
    } else {
        std::cout << "Not ALL Elements are < 20" << std::endl;
    }

}

void string_transform_test() {
    std::cout << "\n=============== string_transform_test() ===================" << std::endl;

    std::string str {"This is a test"};
    std::cout << "Before str = " << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);
    std::cout << "After str = " << str << std::endl;
}

int main() {
    find_test_int(3);
    find_test_int(7);

    find_test_person();

    count_test(1);
    count_test(2);

    count_if_test();

    replace_test();

    all_of_test();
    string_transform_test();
    return 0;
}