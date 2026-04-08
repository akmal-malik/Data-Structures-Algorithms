// Problem: Find median from data stream
// ------------------------------------------------------------
// Problem Description:
// Given a continuous stream of numbers, find the median of all numbers so far.
// The median is the middle value in an ordered integer list. If the size of the list is even,
// there is no single middle value, and the median is the average of the two middle values.
// ------------------------------------------------------------
// Approach: Two Heaps
// Use a max-heap to store the smaller half of the numbers and a min-heap to store the larger half.
// The top of the max-heap is the largest number in the smaller half, and the top of the min-heap is
// the smallest number in the larger half. If the heaps are balanced or the max-heap has one more element,
// the median can be directly obtained from the tops of the heaps.
// ------------------------------------------------------------
// Time Complexity: O(log n) for inserting a new number, O(1) for getting the median
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
private:
    priority_queue<int> maxHeap; // Max-heap to store the smaller half of numbers
    priority_queue<int, vector<int>, greater<int>> minHeap; // Min-heap to store the larger half of numbers

public:
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }

        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
};