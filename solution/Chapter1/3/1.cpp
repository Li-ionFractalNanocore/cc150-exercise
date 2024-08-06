#include <iostream>
using namespace std;


void urlify(string &s, int l) {
    int i = l - 1, j = s.size() - 1;
    while (i >= 0) {
        if (s[i] == ' ') {
            s[j--] = '0';
            s[j--] = '2';
            s[j--] = '%';
        } else {
            s[j--] = s[i];
        }
        i--;
    }
}


int main() {
    string s;
    getline(cin, s);
    int end = s.size();
    int l = s.size();
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            l += 2;
        }
    }
    for (int i = s.size(); i < l; i++) {
        s.push_back(' ');
    }
    urlify(s, end);
    cout << s << endl;
    return 0;
}