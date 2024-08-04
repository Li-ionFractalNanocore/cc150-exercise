// Question: 判定是否互为字符重排。给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。

#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    unordered_map<char, int> char_map;
    for (char c : a) {
        char_map[c]++;
    }
    for (char c : b) {
        if (char_map[c] == 0) {
            cout << "0" << endl;
            return 0;
        } else {
            char_map[c]--;
        }
    }
    cout << "1" << endl;
    return 0;
}