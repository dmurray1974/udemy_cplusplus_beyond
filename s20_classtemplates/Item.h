//
// Created by Darren Murray on 30/08/2026.
//

#ifndef S20_CLASSTEMPLATES_ITEM_H
#define S20_CLASSTEMPLATES_ITEM_H

//Template classes are typically completely contained in header files
// So, we would have the templates class in item.h and no item.cpp
template <typename T>
class Item {
private:
    std::string name;
    T value;
public:
    Item(std::string name, T value) : name(name), value(value) {}
    std::string getName() const { return name; }
    T getValue() const { return value; }
};

template <typename T1, typename T2>
struct myPair {
    T1 first;
    T2 second;
};
#endif //S20_CLASSTEMPLATES_ITEM_H