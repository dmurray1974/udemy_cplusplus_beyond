#include <iostream>
#include <vector>

using namespace std;

class Move {
private:
    int *data;

public:
    void set_data_value(int d) {
        *data = d;
    }
    int get_data_value() {
        return *data;
    }

    //Constructor
    Move(int d);

    //Copy Constructor
    Move(const Move& b);

    //Move Constructir
    Move(Move &&source) noexcept;

    //Desctructor
    ~Move();
};

//Constructor
Move::Move(int d) {
    cout << "Constructor for: " << d << endl;
    data = new int;
    *data = d;
}

// Copy Constructor
Move::Move(const Move& source)
    : Move {*source.data} {
    cout << "Copy Constructor for: " << *data << endl;
}

//Move Constructor
Move::Move(Move &&source) noexcept
 : data{source.data} {
    cout << "Move Constructor for: " << data << endl;
    source.data = nullptr;
}

//Desctructor
Move::~Move() {
    if (data != nullptr) {
        cout << "Destructor freeing data for: value [" << *data << "] at " << data << endl;
    } else {
        cout << "Destructor allocating data for: nullptr" << endl;
    }
    delete data;
}

int main() {
    vector<Move> vec;

    vec.push_back(Move{10});

    return 0;
}