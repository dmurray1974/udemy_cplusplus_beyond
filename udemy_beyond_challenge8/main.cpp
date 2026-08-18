#include <iostream>
#include <compare>

using namespace std;

int main() {


    const int pound_value {100};
    const int fifty_value {50};
    const int twenty_value {20};
    const int ten_value {10};
    const int five_value {5};
    const int two_value {2};
    const int one_value {1};

    int pound_count {0};
    int fifty_count {0};
    int twenty_count {0};
    int ten_count {0};
    int five_count {0};
    int two_count {0};
    int one_count {0};

    cout << "In the UK" << endl;
    cout << "\t1 Pound is " << pound_value << " pence " << endl;
    cout << "\t1 50p is " << fifty_value << " pence " << endl;
    cout << "\t1 20p is " << twenty_value << " pence " << endl;
    cout << "\t1 10p is " << ten_value << " pence " << endl;
    cout << "\t1 5p is " << five_value << " pence " << endl;
    cout << "\t1 2p is " << two_value << " pence " << endl;
    cout << "\t1 1p is " << one_value << " pence " << endl;

    long long pence_entered {0};

    std::cout << endl <<  "Please Enter an Integer representing the number of Pence: " << std::endl;

    cin >> pence_entered;
    long long pence_original = pence_entered;

    //cout << "Pence entered: " << pence_original << endl;

    pound_count = pence_entered / pound_value;
    pence_entered %= pound_value;

    fifty_count = pence_entered / fifty_value;
    pence_entered %= fifty_value;

    twenty_count = pence_entered / twenty_value;
    pence_entered %= twenty_value;

    ten_count = pence_entered / ten_value;
    pence_entered %= ten_value;

    five_count = pence_entered / five_value;
    pence_entered %= five_value;

    two_count = pence_entered / two_value;
    pence_entered %= two_value;

    one_count = pence_entered / one_value;
    pence_entered %= one_value;

    cout << endl;
    cout << "£1 Coins: " << pound_count << endl;
    cout << "50p Coins: " << fifty_count << endl;
    cout << "20p Coins: " << twenty_count << endl;
    cout << "10p Coins: " << ten_count << endl;

    cout << "5p Coins: " << five_count << endl;
    cout << "2p Coins: " << two_count << endl;
    cout << "1p Coins: " << one_count << endl;

    cout << endl << "Remaining Pence: " << pence_entered << endl;

    long long pence_total {0};
    pence_total += (pound_value * pound_count) ;
    pence_total += (fifty_value * fifty_count);
    pence_total += (twenty_value * twenty_count);
    pence_total += (ten_value  * ten_count);
    pence_total += (five_value  * five_count);
    pence_total += (two_value * two_count);
    pence_total += (one_value * one_count);


    cout << endl << "Total Coins Pence : " << pence_total << endl;
    if (pence_original == pence_total) {
        cout <<  " The values are equal" << endl;
    } else {
        cout << "The values are incorrect"  << endl;
    }

    auto cmp = 100 <=> 10;
    int result = (cmp == 0) ? 0 : (cmp < 0 ? -1 : 1);

    std::cout << "TEST: " << result << std::endl;
    if (cmp == 0) {
        std::cout << "TEST: equal" << std::endl;
    } else if (result < 0) {
        std::cout << "TEST: less" << std::endl;
    } else {
        std::cout << "TEST: greater" << std::endl;
    }
    return 0;
}