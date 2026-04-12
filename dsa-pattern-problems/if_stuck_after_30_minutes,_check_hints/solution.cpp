// Problem: If stuck after 30 minutes, check hints/solution
// ------------------------------------------------------------
// Problem Description:
// Given a sorted array of integers and a target integer, return the index of the target if it is found in the array. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.
// ------------------------------------------------------------
// Approach: Binary Search
// Binary search is used to efficiently find the target by repeatedly dividing the search interval in half.
// Start with two pointers, left and right, at the beginning and end of the array respectively. Calculate the middle index and compare the element at this index with the target. If the target is equal to the middle element, return the middle index. If the target is less than the middle element, search in the left half; otherwise, search in the right half. Repeat until the target is found or the search interval is exhausted.
// ------------------------------------------------------------
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return -1;
    }
};