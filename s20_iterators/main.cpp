#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

// Display any vector of integers using range based loop
void display(const std::vector<int> &vec) {
    std::cout << "[";
    for (auto &i : vec) {
        std::cout << i << ", ";
    }
    std::cout << "]" << std::endl;
}

void test1() {
    std::cout << "\n============================================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.begin();
    std::cout << *it << std::endl;

    it++;
    std::cout << *it << std::endl;

    it += 2;
    std::cout << *it << std::endl;

    it -= 2;
    std::cout << *it << std::endl;

    it = nums1.end() -2;
    std::cout << *it << std::endl;

}


void test2() {
    std::cout << "\n=============Test 2()================================" << std::endl;

    std::vector<int> nums1 {1, 2, 3, 4, 5};

//    auto it = nums1.begin();
    std::vector<int>::iterator it = nums1.begin();
    while (it != nums1.end()) {
        std::cout << *it << std::endl;
        it++;
    }

    it = nums1.begin();
    while (it != nums1.end()) {
        *it = 0;
        it++;
    }

    display(nums1);
}

void test3() {

    // Using a const Iterator
    std::cout << "\n============Test 3()===============================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};

    // auto it1 = nums1.cbegin();
    std::vector<int>::const_iterator it1 = nums1.begin();

    while (it1 != nums1.end()) {
        std::cout << *it1 << std::endl;
        it1++;
    }

    // Compiler error when we try to change element
    it1 = nums1.begin();
    while (it1 != nums1.end()) {
     //   *it1 = 0;
        it1++;
    }
}

void test4() {
    std::cout << "\n============Test 4()===============================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5};
    auto it = nums1.rbegin();
    while (it != nums1.rend()) {
        std::cout << *it << std::endl;
        it++;
    }

    // Const reverse iterator over a list
    std::list<std::string> name {"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin();
    std::cout << *it2 << std::endl;
    it2++;
    std::cout << *it2 << std::endl;

    // iterate over a map
    std::map<std::string, std::string> favourites {
            {"Frank", "C++"},
            {"Bill", "Java"},
            {"James", "Haskell"}
    };

    auto it3 = favourites.begin();
    while (it3 != favourites.end()) {
        std::cout << it3->first << ":" << it3->second << std::endl;
        it3++;
    }

}

void test5() {
    std::cout << "\n============Test 5()=================================" << std::endl;
    std::vector<int> nums1 {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = nums1.begin() + 2;
    auto finish = nums1.end() - 3;

    while (start != finish) {
        std::cout << *start << std::endl;
        start++;
    }
}


int main() {
    test1();
    test2();
    test3();
    test4();
    test5();
    return 0;
}