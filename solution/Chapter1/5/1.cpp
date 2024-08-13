#include <iostream>
using namespace std;

bool check(string &a, string &b) {
    if (a.size() < b.size()) {
        string c = a;
        a = b;
        b = c;
    }
    if (a.size() - b.size() > 1) {
        return false;
    }
    if (a.size() > b.size()) {
        int i = 0, j = 0;
        bool diff = false;
        while (i < a.size() && j < b.size()) {
            if (a[i] != b[j]) {
                if (diff) {
                    return false;
                }
                diff = true;
                i++;
            } else {
                i++;
                j++;
            }
        }
        return true;
    }
    if (a == b) {
        return true;
    }
    bool diff = false;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) {
            if (diff) {
                return false;
            }
            diff = true;
        }
    }
    return true;
}

int main() {
    string str_a, str_b;
    while (cin >> str_a >> str_b) {
        if (check(str_a, str_b)) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }
    return 0;
}