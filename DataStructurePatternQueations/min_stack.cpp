// Problem: Min stack
// ------------------------------------------------------------
// Problem Description:
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
// ------------------------------------------------------------
// Approach: Two Stacks
// Use one stack for storing all the elements and another stack to keep track of the minimum elements.
// Push the new element onto the main stack. If the new element is smaller than or equal to the current minimum, push it onto the min stack as well.
// For pop operation, if the element being popped is the current minimum, pop it from both stacks. Otherwise, only pop it from the main stack.
// For the top operation, return the top element of the main stack.
// For retrieving the minimum, return the top element of the min stack.
// ------------------------------------------------------------
// Time Complexity: O(1) for push, pop, top, and getMin operations.
// Space Complexity: O(n) where n is the number of elements in the stack.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> mainStack;
    stack<int> minStack;

public:
    void push(int x) {
        mainStack.push(x);
        if (minStack.empty() || x <= minStack.top()) {
            minStack.push(x);
        }
    }

    void pop() {
        if (!mainStack.empty()) {
            if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    }

    int top() {
        if (!mainStack.empty()) {
            return mainStack.top();
        }
        return -1; // Assuming the stack is not empty
    }

    int getMin() {
        if (!minStack.empty()) {
            return minStack.top();
        }
        return -1; // Assuming the stack is not empty
    }
};