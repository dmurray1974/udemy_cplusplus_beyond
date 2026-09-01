//
// Created by Darren Murray on 30/08/2026.
//

#ifndef S20_ARRAYTEMPLATECLASS_ARRAY_H
#define S20_ARRAYTEMPLATECLASS_ARRAY_H

template <typename T, int N>
class Array {
    int size {N};
    T values[N];

    friend std::ostream& operator<<(std::ostream& os, const Array<T, N>& arr) {
        os << "[";
        for (const auto& i : arr.values) {
            os << i << ", ";
        }
        os << "]" << std::endl;
        return os;
    }
public:
    Array() = default;
    Array(T init_val) {
        for (auto& item : values) {
            item = init_val;
        }
    }
    void fill(T val) {
        for (auto& item : values) {
            item = val;
        }
    }
    int get_size() const {
        return size;
    }
    //Overload the subscript operator
    T &operator[](int index) {
        return values[index];
    }
};

#endif //S20_ARRAYTEMPLATECLASS_ARRAY_H