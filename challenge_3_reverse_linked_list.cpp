#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v, Node* n = nullptr) : val(v), next(n) {}
};

// Time: O(n), Space: O(1)
Node* reverseList(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr) {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node* buildList(const vector<int>& values) {
    Node* head = nullptr;
    Node* tail = nullptr;
    for (int v : values) {
        Node* n = new Node(v);
        if (!head) { head = tail = n; }
        else { tail->next = n; tail = n; }
    }
    return head;
}

vector<int> toVector(Node* head) {
    vector<int> out;
    while (head) { out.push_back(head->val); head = head->next; }
    return out;
}

void freeList(Node* head) {
    while (head) { Node* n = head->next; delete head; head = n; }
}

int main() {
    Node* a = buildList({1, 2, 3});
    Node* ra = reverseList(a);
    assert((toVector(ra) == vector<int>{3, 2, 1}));
    freeList(ra);

    Node* b = buildList({});
    Node* rb = reverseList(b);
    assert((toVector(rb) == vector<int>{}));

    Node* c = buildList({5});
    Node* rc = reverseList(c);
    assert((toVector(rc) == vector<int>{5}));
    freeList(rc);

    cout << "All Challenge 3 tests passed." << endl;
    return 0;
}
