#include <iostream>
#include <queue>


// This is pass by value, so will create a copy and not nodify original queue
template <typename T>
void display(std::queue<T> q) {
    std::cout << "[ ";
    while (!q.empty()) {
        T item = q.front();
        q.pop();
        std::cout << item << " ";
    }
    std::cout << "]" << std::endl;
}


int main() {
    std::queue<int> q;

    for (int i : {1, 2, 3, 4, 5, 6, 7, 8, 9}) {
        q.push(i);
    }
    display(q);

    std::cout << "Front : " << q.front() << std::endl;
    std::cout << "Rear  : " << q.back() << std::endl;

    q.push(100);
    display(q);

    q.pop();
    q.pop();
    display(q);

    while (!q.empty()) {
        q.pop();
    }

    display(q);

    std::cout << "Size: " << q.size() << std::endl;

    q.push(100);
    q.push(200);
    q.push(300);
    display(q);

    std::cout << "Front : " << q.front() << std::endl;
    std::cout << "Rear  : " << q.back() << std::endl;

    q.front() = 5;
    q.back() = 5000;

    display(q);
    std::cout << "Front : " << q.front() << std::endl;
    std::cout << "Rear  : " << q.back() << std::endl;

    return 0;
}