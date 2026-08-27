#include <iostream>
#include <memory>

class Test {
private:
    int data;
public:
    Test() : data{0} {
        std::cout << "Test constructor {" << data << ")" <<  std::endl;
    }
    Test(int data) : data{data} {
        std::cout << "Test constructor {" << data << ")" <<  std::endl;
    }

    ~Test() {
        std::cout << "Test Destructor {" << data << ")" <<  std::endl;
    }
};

void myDeleter(Test* ptr) {
    std::cout << "In my Custom deleter" << std::endl;
    delete ptr;
}

int main() {

    std::shared_ptr<Test> ptr = { new Test(0), myDeleter };

 //   std::unique_ptr<Test> t1 {new Test(100)};
 //   std::unique_ptr<Test> t2 = std::make_unique<Test>(1000);

 //   std::unique_ptr<Test> t3;
 //   t3 = std::move(t1);

//    if (!t1) {
//        std::cout << "t1 is a nullptr" << std::endl;
//    }

    /*
    std::unique_ptr<int> p1 {new int {100}};
    std::unique_ptr<int> p2 {new int {200}};

    std::cout << *p1 << std::endl;
    *p2 = *p1;

    std::cout << *p2 << std::endl;

    // Some examples for Account Class
    std::vector<std::unique_ptr<Account>> accounts;

    accounts.push_back(make_unique<Checking_Account>("James", 1000, 1,23));

    for (const auto &acc : accounts) {
        std::cout << *acc << std::endl;
    }



*/
    return 0;
}