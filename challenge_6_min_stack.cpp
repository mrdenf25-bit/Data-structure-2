#include <iostream>
#include <stack>
#include <stdexcept>
#include <cassert>
using namespace std;

// All operations O(1), Space: O(n) for the extra min stack
class MinStack {
public:
    void push(int x) {
        st.push(x);
        if (minSt.empty() || x < minSt.top()) {
            minSt.push(x);
        } else {
            minSt.push(minSt.top());
        }
    }

    void pop() {
        if (st.empty()) {
            throw runtime_error("pop from empty stack");
        }
        st.pop();
        minSt.pop();
    }

    int top() {
        if (st.empty()) {
            throw runtime_error("top from empty stack");
        }
        return st.top();
    }

    int getMin() {
        if (minSt.empty()) {
            throw runtime_error("getMin from empty stack");
        }
        return minSt.top();
    }

private:
    stack<int> st;
    stack<int> minSt;
};

int main() {
    MinStack s;
    s.push(3);
    s.push(5);
    s.push(2);
    assert(s.getMin() == 2);
    s.pop();
    assert(s.getMin() == 3);
    assert(s.top() == 5);

    MinStack d;
    d.push(1);
    d.push(1);
    d.pop();
    assert(d.getMin() == 1);

    MinStack e;
    bool threw = false;
    try {
        e.pop();
    } catch (const runtime_error&) {
        threw = true;
    }
    assert(threw);

    cout << "All Challenge 6 tests passed." << endl;
    return 0;
}
