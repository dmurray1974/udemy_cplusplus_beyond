#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b);
void print(const vector<int> &v);
void update_vector(vector<int> &v, size_t element, int new_val);


int main() {
    int x{10}, y{20};
    cout << x << " " << y << endl;
    swap(x, y);
    cout << x << " " << y << endl;

    cout << endl << endl;

    vector<int> data { 1, 2, 3, 4, 5};
    print(data);
    update_vector(data, 3, 10);
    print(data);

    return 0;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void print(const vector<int> &v) {
    cout << endl << "Printing Vector" << endl;
    for (auto i : v) {
        cout << i << endl;
    }
}

void update_vector(vector<int> &v, size_t element, int new_val) {
    cout << endl << "Updating Vector" << endl;
    if ( element < v.size() ) {
        v[element] = new_val;
    }
}