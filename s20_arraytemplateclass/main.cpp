#include <iostream>
#include <string>
#include "Array.h"



int main() {
    Array<int, 5> nums {88};
    std::cout << "The size is " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(0);
    std::cout << "The size is " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;

    nums.fill(10);
    std::cout << nums << std::endl;

    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    std::cout << std::endl << std::endl;
    Array<std::string, 10> strings(std::string{"John"});

    std::cout << "The size is " << strings.get_size() << std::endl;
    std::cout << strings << std::endl;

    strings.fill("PLOP");
    std::cout << "The size is " << strings.get_size() << std::endl;
    std::cout << strings << std::endl;

    strings.fill("JUMPERT");
    std::cout << strings << std::endl;

    strings[0] = "HappyDays";
    strings[3] = "ShugWozEre";
    std::cout << strings << std::endl;




    return 0;
}