#include <iostream>
#include <string>
#include <vector>
#include "Item.h"



int main() {
    Item<int> item1("John", 100);
    std::cout << item1.getName() << ", " << item1.getValue() << std ::endl;

    Item<std::string> item2("John", "Professor");
    std::cout << item2.getName() << ", " << item2.getValue() << std ::endl;

    Item<Item<std::string>> item3{"John", {"C++", "Professor"}};
    std::cout << item3.getName() << ", "
              << item3.getValue().getName() << ", "
              << item3.getValue().getValue() << std ::endl;


    std::cout << "================================" << std::endl << std::endl;

    std::vector<Item<double>> vec {};
    vec.push_back(Item<double>("Larry", 100.6));
    vec.push_back(Item<double>("Curly", 200.1));
    vec.push_back(Item<double>("Moe", 300.3));

    for (const auto& item : vec) {
        std::cout << item.getName() << ", " << item.getValue() << std::endl;
    }

    return 0;
}