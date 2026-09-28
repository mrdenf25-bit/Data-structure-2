#include <iostream>
#include <cassert>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(nullptr) {}
};

// Time: O(n), Space: O(1)
bool hasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;
        }
    }
    return false;
}

int main() {
    Node n1(1), n2(2), n3(3), n4(4), n5(5);
    n1.next = &n2;
    n2.next = &n3;
    n3.next = &n4;
    n4.next = &n5;
    assert(!hasCycle(&n1));

    n5.next = &n3;
    assert(hasCycle(&n1));

    assert(!hasCycle(nullptr));

    Node single(7);
    assert(!hasCycle(&single));
    single.next = &single;
    assert(hasCycle(&single));

    cout << "All Challenge 5 tests passed." << endl;
    return 0;
}
