// Problem: Stacks & Queues (19 problems)
// ------------------------------------------------------------
// Problem Description:
// Implement a stack using two queues.
// You only can use standard operations of a queue, which includes push to back, peek/pop from front, size and is empty.
// Also, you need to support additional operation like getMin() which should return the minimum element in the stack.
// ------------------------------------------------------------
// Approach: Two Queues
// Use one queue for stack operations and another queue as an auxiliary queue. 
// Push operation can be done directly into the primary queue.
// Pop operation involves transferring elements from the primary queue to the auxiliary queue until only the last element is left, which is then removed and returned.
// getMin() operation utilizes the secondary queue to keep track of minimum values during each push operation.
// ------------------------------------------------------------
// Time Complexity: 
// Push: O(1)
// Pop: O(n)
// Top: O(1)
// Min: O(1)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    queue<int> primaryQueue;
    queue<int> minQueue;

public:
    void push(int x) {
        primaryQueue.push(x);
        if (minQueue.empty() || x <= minQueue.front()) {
            minQueue.push(x);
        }
    }

    void pop() {
        int top = primaryQueue.front();
        primaryQueue.pop();

        if (top == minQueue.front()) {
            minQueue.pop();
        }
    }

    int top() {
        return primaryQueue.front();
    }

    int getMin() {
        return minQueue.front();
    }
};
