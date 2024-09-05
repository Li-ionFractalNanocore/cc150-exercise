#include "../common/linklist.hpp"


Node* splitLinkList(Node *head, int x) {
    Node large, small, *tail;
    Node *p = head;
    while (p) {
        Node *t = p->next;
        if (p->data < x) {
            p->next = small.next;
            small.next = p;
            if (p->next == nullptr) {
                tail = p;
            }
        } else {
            p->next = large.next;
            large.next = p;
        }
        p = t;
    }
    if (tail == nullptr) {
        return large.next;
    }
    tail->next = large.next;
    return small.next;
}


int main() {
    int n = 7;
    int nums[] = {3, 5, 8, 5, 10, 2, 1};
    Node head;
    Node *p = &head;
    for (int i = 0; i < n; i++) {
        p->next = new Node(nums[i]);
        p = p->next;
    }
    Node *r = splitLinkList(head.next, 5);
    printList(r);
    return 0;
}
