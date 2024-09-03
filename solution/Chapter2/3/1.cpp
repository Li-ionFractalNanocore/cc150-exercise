#include <iostream>
#include "../common/linklist.hpp"
using namespace std;

Node* solve(Node *remove) {
    if (remove == nullptr or remove->next == nullptr) {
        return nullptr;
    }
    Node *next = remove->next;
    remove->data = next->data;
    remove->next = next->next;
    delete next;
    return remove;
}

int main() {
    Node *head = readToList();
    Node *remove = head;
    int removeData;
    cin >> removeData;
    while (remove != nullptr and remove->data != removeData) {
        remove = remove->next;
    }
    solve(remove);
    printList(head);
    return 0;
}