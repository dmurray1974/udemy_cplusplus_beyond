#include <iostream>
#include <string>
using namespace std;

string encrypt(string message) {
    string key1 {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789"};
    string key2 {"ghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdef"};
    string encrypted {};
    size_t pos;
    for (auto c : message) {
        pos = key1.find(c);
        if (pos != string::npos) {
            encrypted += key2.at(pos);
        } else {
            encrypted += c;
        }

    }
    return encrypted;
}

string decrypt(string message) {
    string key1 {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789"};
    string key2 {"ghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ 0123456789abcdef"};
    string encrypted {};
    size_t pos;
    for (auto c : message) {
        pos = key2.find(c);
        if (pos != string::npos) {
            encrypted += key1.at(pos);
        } else {
            encrypted += c;
        }

    }
    return encrypted;
}

int main() {

    string encrypted_message {};
    string decrypted_message {};

    const string message {"Hello! World I am here and PLOPPe 123"};
    encrypted_message = encrypt(message);
    cout << "Original message : " << message << endl;
    cout << "Encrypted: " << encrypted_message << endl;
    decrypted_message = decrypt(encrypted_message);
    cout << "Decrypted: " << decrypted_message << endl;
    return 0;
}