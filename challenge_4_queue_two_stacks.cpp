#include <iostream>
#include <stack>
#include <stdexcept>
#include <cassert>
using namespace std;

// enqueue: O(1), dequeue: O(1) amortized (O(n) worst case), Space: O(n)
class QueueFromStacks {
public:
    void enqueue(int x) {
        in.push(x);
    }

    int dequeue() {
        if (out.empty()) {
            while (!in.empty()) {
                out.push(in.top());
                in.pop();
            }
        }
        if (out.empty()) {
            throw runtime_error("dequeue from empty queue");
        }
        int front = out.top();
        out.pop();
        return front;
    }

private:
    stack<int> in;
    stack<int> out;
};

int main() {
    QueueFromStacks q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    assert(q.dequeue() == 1);
    q.enqueue(4);
    assert(q.dequeue() == 2);
    assert(q.dequeue() == 3);
    assert(q.dequeue() == 4);

    bool threw = false;
    try {
        q.dequeue();
    } catch (const runtime_error&) {
        threw = true;
    }
    assert(threw);

    cout << "All Challenge 4 tests passed." << endl;
    return 0;
}
