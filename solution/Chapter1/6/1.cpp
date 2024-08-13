#include <iostream>
using namespace std;


int main() {
    string s;
    cin >> s;
    int count = 0;
    string result;
    for (int i = 0; i < s.size(); i++) {
        count++;
        if (i + 1 >= s.size() || s[i] != s[i + 1]) {
            result += s[i];
            result += to_string(count);
            count = 0;
        }
    }
    if (result.size() < s.size()) {
        cout << result << endl;
    } else {
        cout << s << endl;
    }
    return 0;
}