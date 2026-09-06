#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>    // For std::iota


void test1() {
    std::cout << "============== TEST1() ================" << std::endl;

    std::vector<int> nums {10,20,30,40,50,60,70,80,90};

    std::for_each(nums.begin(),
                  nums.end(),
                  [](int num) {         // Lambda operation
        std::cout << num << " ";
    });
    std::cout << std::endl;
}


// Permutation, are 2 triangles equiv
void test2() {
    std::cout << "============== TEST2() =============" << std::endl;

    struct Point {
        int x, y;
    };

    Point p1 {1,2};
    Point p2 {4,3};
    Point p3 {3,5};
    Point p4 {3,1};

    std::vector<Point> triangle1 {p1, p2, p3};
    std::vector<Point> triangle2 {p2, p3, p1};
    std::vector<Point> triangle3 {p2, p2, p4};

    if (std::is_permutation(triangle1.begin(),
                            triangle1.end(),
                            triangle2.begin(),
                            [](Point lhs, Point rhs) {
                                return lhs.x == rhs.x && lhs.y == rhs.y;
                            })
    ) {
        std::cout << "Triangle 1 and Triangle2 are equivalent" << std::endl;
    } else {
        std::cout << "Triangle 1 and Triangle2 are not equivalent" << std::endl;
    }

    if (std::is_permutation(triangle1.begin(),
                        triangle1.end(),
                        triangle3.begin(),
                        [](Point lhs, Point rhs) {
                            return lhs.x == rhs.x && lhs.y == rhs.y;
                        })
    ) {
        std::cout << "Triangle 1 and Triangle3 are equivalent" << std::endl;
    } else {
        std::cout << "Triangle 1 and Triangle3 are not equivalent" << std::endl;
    }
}

// Transform - Modifying Operation
void test3() {
    std::cout << "============== TEST3() =============" << std::endl;

    std::vector<int> test_scores {93,88,75,68,65};
    int bonus_points {5};

    std::cout << "Original scores:                ";
    for (int score : test_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;

    std::transform(test_scores.begin(),
                    test_scores.end(),
                    test_scores.begin(),
                     [bonus_points](int score) {
                         return score += bonus_points;
                     });

    std::cout << "Transform scores[+BonusPoints]: ";
    for (int score : test_scores) {
        std::cout << score << " ";
    }
    std::cout << std::endl;
}

void test4() {
    std::cout << "============== TEST4() =============" << std::endl;

    std::vector<int> nums {10,20,30,40,50,60,70,80,80,90};
    // Display Updated Numbers
    std::cout << "[" ;
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;

    nums.erase(std::remove_if(nums.begin(),
        nums.end(),
        [](int num) {
            return num %2 == 0;
        }),
        nums.end());

    // Display Updated Numbers
    std::cout << "[" ;
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << "]" << std::endl;
}

void test5() {
    std::cout << "============== TEST5() =============" << std::endl;
}

void test6() {
    std::cout << "============== TEST6() ============" << std::endl;
}


class Password_Validator1 {
private:
    char restricted_symbol {'$'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(),
            password.end(),
            [this] (char character) {
                return character != restricted_symbol;
            });
    }
};

class Password_Validator2 {
private:
    std::vector<char> restricted_symbols {'!', '$', '+'};
public:
    bool is_valid(std::string password) {
        return std::all_of(password.begin(),
            password.end(),
            [this] (char character) {
                return std::none_of(restricted_symbols.begin(),
                    restricted_symbols.end(),
                    [character] (char symbol) {
                        return character == symbol;
                    });
            });
    }
};

void test7() {
    std::cout << "============== TEST7() ============" << std::endl;

    std::string password {"holyrod1$"};
    Password_Validator1 pv1;

    // Tes whether password is valid
    if (pv1.is_valid(password)) {
        std::cout << "Password " << password << " is valid" << std::endl;
    } else {
        std::cout << "Password " << password << " is invalid" << std::endl;
    }

    // Tes whether new password is valid
    password = "holyrod1";
    if (pv1.is_valid(password)) {
        std::cout << "Password " << password << " is valid" << std::endl;
    } else {
        std::cout << "Password " << password << " is invalid" << std::endl;
    }
    std::cout << std::endl;

    // Password validator2
    password = "C++Rocks!";
    Password_Validator2 pv2;
    if (pv2.is_valid(password)) {
        std::cout << "Password " << password << " is valid" << std::endl;
    } else {
        std::cout << "Password " << password << " is invalid" << std::endl;
    }

    // Tes whether new password is valid
    password = "holyrod1";
    if (pv2.is_valid(password)) {
        std::cout << "Password " << password << " is valid" << std::endl;
    } else {
        std::cout << "Password " << password << " is invalid" << std::endl;
    }
    std::cout << std::endl;
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