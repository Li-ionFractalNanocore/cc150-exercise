#include <iostream>
#include <unordered_map>
using namespace std;


int main() {
    string s;
    getline(cin, s);
    unordered_map<char, int> char_count;
    for (char &c : s) {
        char uniform_c = tolower(c);
        if (uniform_c >= 'a' && uniform_c <= 'z') {
            char_count[uniform_c]++;
        }
    }
    bool odd = false;
    for (auto &p : char_count) {
        if ((p.second & 1) == 1) {
            if (!odd) {
                odd = true;
            } else {
                cout << "False" << endl;
                return 0;
            }
        }
    }
    cout << "True" << endl;
    return 0;
}