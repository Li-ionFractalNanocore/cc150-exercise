#include <string>
#include "../common/linklist.hpp"
using namespace std;


int cal_length(Node *s) {
    int len = 0;
    while (s) {
        len++;
        s = s->next;
    }
    return len;
}

Node* is_parlindrome_r(Node *s, int len) {
    if (len == 0) {
        return s;
    }
    if (len == 1) {
        return s->next;
    }
    Node *t = is_parlindrome_r(s->next, len - 2);
    if (t == nullptr) {
        return nullptr;
    }
    if (s->data == t->data) {
        return t->next;
    }
    return nullptr;
}

bool is_parlindrome(Node *s) {
    int length = cal_length(s);
    int now = s->data;
    Node* is_p = is_parlindrome_r(s, length);
    if (is_p == nullptr) {
        return false;
    }
    return true;
}