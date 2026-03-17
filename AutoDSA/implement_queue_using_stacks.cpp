// Problem: Implement queue using stacks
// ------------------------------------------------------------
// Problem Description:
// Implement a first in first out (FIFO) queue using only two stacks. 
// The implemented queue should support all the functions of a normal queue 
// (push, pop, peek, and empty).
// ------------------------------------------------------------
// Approach: Two Stacks
// Use two stacks to simulate the queue operations. 
// The push operation adds an element to the top of the first stack.
// The pop and peek operations transfer elements from the first stack to the second stack 
// to reverse the order, ensuring that the oldest element is on the top of the second stack.
// The empty operation checks if both stacks are empty.
// ------------------------------------------------------------
// Time Complexity: 
// push - O(1)
// pop - O(n) in the worst case, O(1) on average
// peek - O(n) in the worst case, O(1) on average
// empty - O(1)
// Space Complexity: O(n) for two stacks
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class MyQueue {
private:
    stack<int> inStack, outStack;

public:
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        int x = outStack.top();
        outStack.pop();
        return x;
    }

    /** Get the front element. */
    int peek() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
        return outStack.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};