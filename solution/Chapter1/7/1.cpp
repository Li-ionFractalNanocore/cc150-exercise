#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }
    for (int l = 0; l < n / 2; l++) {
        for (int i = l; i < n - l - 1; i++) {
            int temp = matrix[l][i];
            matrix[l][i] = matrix[i][n - l - 1];
            matrix[i][n - l - 1] = matrix[n - l - 1][n - i - 1];
            matrix[n - l - 1][n - i - 1] = matrix[n - i - 1][l];
            matrix[n - i - 1][l] = temp;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << matrix[i][0];
        for (int j = 1; j < n; j++)
            cout << " " << matrix[i][j];
        cout << endl;
    }
    return 0;
}