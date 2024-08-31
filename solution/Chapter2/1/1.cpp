#include "../common/linklist.hpp"

int main() {
    Node* head = readToList();
    Node* p = head;
    while (p != nullptr and p->next != nullptr) {
        if (p->data == p->next->data) {
            Node* q = p->next;
            p->next = q->next;
            delete q;
        } else {
            p = p->next;
        }
    }
    printList(head);
    return 0;
}