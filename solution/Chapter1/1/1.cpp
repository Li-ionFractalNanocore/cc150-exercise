#include <iostream>
#include <unordered_set>
using namespace std;

bool check_unique(string s) {
    unordered_set<char> char_set;
    for (char c : s) {
        if (char_set.find(c) != char_set.end()) {
            return false;
        }
        char_set.insert(c);
    }
    return true;
}

bool check_unique_withou_data_structure(string s) {
    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            if (s[i] == s[j]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    if (check_unique(s)) {
        cout << 1 << endl;
    } else {
        cout << 0 << endl;
    }
    return 0;
}