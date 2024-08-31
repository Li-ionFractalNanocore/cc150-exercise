#ifndef LINKLIST_HPP
#define LINKLIST_HPP

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
};

Node* readToList();
void printList(Node* head);

#endif