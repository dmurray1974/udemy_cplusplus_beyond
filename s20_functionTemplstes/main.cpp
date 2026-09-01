#include <iostream>
#include <string>

template <typename T>
T min(T a, T b) {
    return (a < b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b) {
    std::cout << a << ", " << b << std::endl;
}

struct Person {
    std::string name;
    int age;
    bool operator<(const Person& other) const {
        return age < other.age;
    }
};

std::ostream& operator<<(std::ostream& os, const Person& person) {
    os << person.name << " : " << person.age;
    return os;
}

template <typename T>
void mySwap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    Person p1 {"Curly", 50};
    Person p2 {"David", 25};
    Person p3 = min(p1, p2);
    std::cout << p3.name << " is younger" << std::endl;


    std::cout << min<int>(1, 2) << std::endl;
    std::cout << min(10, 20) << std::endl;
    std::cout << min('A', 'B') << std::endl;
    std::cout << min(12.3, 22.34) << std::endl;
    std::cout << min(5+2*2, 7+40) << std::endl;


    std::cout << std::endl;
    std::cout << "++++++++++ Using Func template" << std::endl;
    func<int, int>(1, 2);
    func(10,20);
    func<char, double>('A', 12.4);
    func(1000, "Testing");
    func(2000, std::string{"Drank"});
    func(p1, p2);


    std::cout << std::endl;
    std::cout << "++++++++++ Using SWAP template" << std::endl;
    int x{1000}, y{200};
    std::cout << "Before: " << x << ", " << y << std::endl;
    mySwap(x, y);
    std::cout << "After : " << x << ", " << y << std::endl;

    return 0;
}