#include <iostream>
#include "../common/linklist.hpp"
using namespace std;

int main() {
    Node *head = readToList();
    int k;
    cin >> k;
    Node *first = head;
    for (int i = 0; i < k; i++) {
        first = first->next;
    }
    Node *slow = head;
    while (first != nullptr) {
        first = first->next;
        slow = slow->next;
    }
    cout << slow->data << endl;
    return 0;
}