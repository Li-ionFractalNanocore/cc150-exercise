#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    if (a.length() != b.length()) {
        cout << "false" << endl;
        return 0;
    }
    b += b;
    if (b.find(a) != string::npos) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}