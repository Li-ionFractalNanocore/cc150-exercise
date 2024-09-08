#include "../common/linklist.hpp"

Node *sum_reverse(Node *a, Node *b) {
    Node *head = new Node(0);
    Node *now = head;
    int carry = 0;
    while (a != nullptr || b != nullptr) {
        int sum = carry;
        if (a != nullptr) {
            sum += a->data;
            a = a->next;
        }
        if (b != nullptr) {
            sum += b->data;
            b = b->next;
        }
        now->next = new Node(sum % 10);
        now = now->next;
        carry = sum / 10;
    }
    if (carry > 0) {
        now->next = new Node(carry);
    }
    return head->next;
}

Node* padding(Node* head, int n) {
    Node* p = head;
    for (int i = 0; i < n; i++) {
        Node* new_node = new Node(0);
        new_node->next = p;
        p = new_node;
    }
    return p;
}

Node* sum_part(Node* a, Node *b, int &carry) {
    if (a == nullptr || b == nullptr) {
        return nullptr;
    }
    int c = 0;
    Node* next = sum_part(a->next, b->next, c);
    int now = a->data + b->data + c;
    carry = now / 10;
    Node *r = new Node(now % 10);
    r->next = next;
    return r;
}

Node* sum_forward(Node* a, Node* b) {
    int len_a = 0, len_b = 0;
    Node* p = a;
    while (p != nullptr) {
        len_a++;
        p = p->next;
    }
    p = b;
    while (p != nullptr) {
        len_b++;
        p = p->next;
    }
    if (len_a < len_b) {
        a = padding(a, len_b - len_a);
    } else {
        b = padding(b, len_a - len_b);
    }
    int carry = 0;
    Node* result = sum_part(a, b, carry);
    if (carry > 0) {
        Node* head = new Node(carry);
        head->next = result;
        result = head;
    }
    return result;
}

int main() {
    Node* head_a = new Node(6);
    head_a->next = new Node(5);
    head_a->next->next = new Node(6);
    Node* head_b = new Node(5);
    head_b->next = new Node(6);
    head_b->next->next = new Node(7);
    Node *result = sum_reverse(head_a, head_b);
    printList(result);
    result = sum_forward(head_a, head_b);
    printList(result);
    return 0;
}