#include <iostream>
#include <bitset>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    const int MAX_CHAR = 26;
    bitset<MAX_CHAR> char_count;
    for (char &c : s) {
        char uniform_c = tolower(c);
        if (uniform_c >= 'a' && uniform_c <= 'z') {
            int index = uniform_c - 'a';
            if (char_count.test(index)) {
                char_count.reset(index);
            } else {
                char_count.set(index);
            }
        }
    }
    bool odd = false;
    for (int i = 0; i < MAX_CHAR; i++) {
        if (char_count.test(i)) {
            if (odd) {
                cout << "False" << endl;
                return 0;
            }
            odd = true;
        }
    }
    cout << "True" << endl;
    return 0;
}