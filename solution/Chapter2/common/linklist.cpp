#include <iostream>
#include "linklist.hpp"

Node* readToList() {
    int n;
    std::cin >> n;
    Node *head = new Node;
    Node *p = head;
    for (int i = 0; i < n; i++) {
        std::cin >> p->data;
        if (i < n - 1) {
            p->next = new Node;
            p = p->next;
        }
    }
    p->next = nullptr;
    return head;
}

void printList(Node* head) {
    Node* p = head;
    while (p != nullptr) {
        std::cout << p->data;
        if (p->next != nullptr) {
            std::cout << " ";
        }
        p = p->next;
    }
    std::cout << std::endl;
}