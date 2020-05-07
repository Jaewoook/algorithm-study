#include <iostream>
#include <algorithm>
using namespace std;

void push(int val, int *heap, int &size) {
    heap[++size] = val;
    if (size == 1) {
        return;
    }

    int parent = size / 2;
    int current = size;

    while (parent >= 1 && heap[current] < heap[parent]) {
        swap(heap[parent], heap[current]);

        current = parent;
        parent = current / 2;
    }
}

int pop(int *heap, int &size) {
    if (size == 0) {
        return 0;
    }

    int result = heap[1];
    swap(heap[1], heap[size--]);
    if (size == 1) {
        return result;
    }

    int current = 1;
    int child = current * 2;
    if (child + 1 <= size) {
        child = heap[child] < heap[child + 1] ? child : child + 1;
    }
    while (child <= size && heap[current] > heap[child]) {
        swap(heap[current], heap[child]);

        current = child;
        child = current * 2;
        if (child + 1 <= size) {
            child = heap[child] < heap[child + 1] ? child : child + 1;
        }
    }

    return result;
}

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);

    int T = 0, x = 0, heap_size = 0;
    cin >> T;
    int *heap = new int[100001];

    while (T--) {
        cin >> x;
        if (x == 0) {
            cout << pop(heap, heap_size) << "\n";
        } else {
            push(x, heap, heap_size);
        }
    }

    delete[] heap;
    return 0;
}
