#include <iostream>

class Shallow {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Shallow(int d);
    // Copy Constructor
    Shallow(const Shallow &source);
    //Destructor
    ~Shallow();
};

Shallow::Shallow(int d) {
    data = new int;
    *data = d;
}

Shallow::Shallow(const Shallow &source)
    :data(source.data) {
        std::cout << "Copy constructor - Shallow Copy" << std::endl;
}

Shallow::~Shallow() {
    delete data;
    std::cout << "Destructor Freeing Memory" << std::endl;
}

void display_shallow(Shallow s) {
    std::cout << s.get_data_value() << std::endl;
}

class Deep {
private:
    int *data;
public:
    void set_data_value(int d) { *data = d; }
    int get_data_value() { return *data; }
    // Constructor
    Deep(int d);
    // Copy Constructor
    Deep(const Deep &source);
    //Destructor
    ~Deep();
};

Deep::Deep(int d) {
    data = new int;
    *data = d;
}

// Copy Constructor
Deep::Deep(const Deep &source) {
    data = new int;
    *data = *source.data;
    std::cout << "Copy constructor - Deep Copy" << std::endl;
}

// Destructor
Deep::~Deep() {
    delete data;
    std::cout << "Deep Destructor Freeing Memory" << std::endl;
}

void display_deep(Deep s) {
    std::cout << s.get_data_value() << std::endl;
}


int main() {

    Deep obj1 {100};
    display_deep(obj1);

    Deep obj2 = Deep(obj1);
    obj2.set_data_value(1000);

    Shallow obj3 {100};
    display_shallow(obj3);

    Shallow obj4 = Shallow(obj3);
    obj4.set_data_value(1000);

    return 0;
}