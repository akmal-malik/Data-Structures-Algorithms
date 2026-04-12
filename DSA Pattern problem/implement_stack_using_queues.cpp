// Problem: Implement stack using queues
// ------------------------------------------------------------
// Problem Description:
// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).
// Implement the MyStack class:
// void push(int x) Pushes element x onto stack.
// int pop() Removes the element on top of the stack and returns that element.
// int top() Returns the element on the top of the stack.
// bool empty() Returns whether the stack is empty.
// Notes:
// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size, and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only standard operations of a queue.
// You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
// ------------------------------------------------------------
// Approach: Two Queues
// Use two queues to simulate the stack behavior. One queue is used to store elements, and the other queue is used to help with the pop and top operations.
// For push operation, simply add the new element to the queue.
// For pop operation, transfer elements from the first queue to the second queue until only one element is left in the first queue. The last element is the one to be popped. Swap the roles of the two queues after the operation.
// For top operation, transfer elements from the first queue to the second queue until only one element is left in the first queue. The last element is the one on the top. Transfer it to the second queue and then swap the roles of the two queues.
// For empty operation, check if the first queue is empty.
// ------------------------------------------------------------
// Time Complexity: 
// push: O(1)
// pop: O(n)
// top: O(n)
// empty: O(1)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    queue<int> q1, q2;
public:
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        int n = q1.size();
        for (int i = 0; i < n - 1; ++i) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        swap(q1, q2);
        return top;
    }
    
    int top() {
        int n = q1.size();
        for (int i = 0; i < n - 1; ++i) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q2.push(q1.front());
        q1.pop();
        swap(q1, q2);
        return top;
    }
    
    bool empty() {
        return q1.empty();
    }
};