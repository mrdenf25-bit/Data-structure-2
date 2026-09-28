#include <iostream>
#include <stdexcept>
#include <cassert>
using namespace std;

// append: O(1) amortized (O(n) when it resizes), get/set: O(1)
class DynamicArray {
public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    ~DynamicArray() {
        delete[] data;
    }

    void append(int x) {
        if (size == capacity) {
            capacity = capacity * 2;
            int* newData = new int[capacity];
            for (int i = 0; i < size; i++) {
                newData[i] = data[i];
            }
            delete[] data;
            data = newData;
        }
        data[size] = x;
        size++;
    }

    int get(int i) {
        if (i < 0 || i >= size) {
            throw out_of_range("index out of range");
        }
        return data[i];
    }

    void set(int i, int x) {
        if (i < 0 || i >= size) {
            throw out_of_range("index out of range");
        }
        data[i] = x;
    }

    int getSize() { return size; }
    int getCapacity() { return capacity; }

private:
    int* data;
    int size;
    int capacity;
};

int main() {
    DynamicArray arr;
    arr.append(10);
    arr.append(20);
    assert(arr.getCapacity() == 2);
    arr.append(30);
    assert(arr.getCapacity() == 4);
    assert(arr.getSize() == 3);
    assert(arr.get(0) == 10 && arr.get(1) == 20 && arr.get(2) == 30);

    arr.set(1, 99);
    assert(arr.get(1) == 99);

    for (int i = 0; i < 10; i++) {
        arr.append(i);
    }
    assert(arr.getSize() == 13);
    assert(arr.getCapacity() == 16);

    bool threw = false;
    try {
        arr.get(13);
    } catch (const out_of_range&) {
        threw = true;
    }
    assert(threw);

    threw = false;
    try {
        arr.set(-1, 5);
    } catch (const out_of_range&) {
        threw = true;
    }
    assert(threw);

    cout << "All Challenge 7 tests passed." << endl;
    return 0;
}
