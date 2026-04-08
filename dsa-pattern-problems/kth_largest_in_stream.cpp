// Problem: Kth largest in stream
// ------------------------------------------------------------
// Problem Description:
// Design a class to find the kth largest element in a stream of numbers.
// It should support adding new numbers and retrieving the kth largest number efficiently.
// ------------------------------------------------------------
// Approach: Min Heap
// Use a min heap to keep track of the k largest elements seen so far. The root of the heap will be the kth largest element.
// ------------------------------------------------------------
// Time Complexity:
// - Constructor: O(1)
// - add: O(log k) for pushing and popping from the heap
// - kthLargest: O(1)
// ------------------------------------------------------------
// Space Complexity: O(k) for storing the elements in the heap
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;
    
    Solution(int k) : size(k) {}
    
    void add(int val) {
        if (minHeap.size() < size) {
            minHeap.push(val);
        } else if (val > minHeap.top()) {
            minHeap.pop();
            minHeap.push(val);
        }
    }
    
    int kthLargest() {
        return minHeap.top();
    }
};