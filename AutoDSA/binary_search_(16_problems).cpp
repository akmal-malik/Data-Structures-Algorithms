// Problem: Binary Search (16 problems)
// ------------------------------------------------------------
// Problem Description:
// Given a sorted array of integers and a target value, write a function to search for the target in the array. If the target is found, return its index. Otherwise, return -1.
// You must implement the algorithm with O(log n) runtime complexity.
// ------------------------------------------------------------
// Approach: Binary Search
// Initialize two pointers, left and right, to the start and end of the array respectively. While left is less than or equal to right, calculate the middle index. If the element at mid is equal to the target, return mid. If the target is smaller than the element at mid, move the right pointer to mid - 1. Otherwise, move the left pointer to mid + 1. If the loop ends without finding the target, return -1.
// ------------------------------------------------------------
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
                return mid;
            else if (target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return -1;
    }
};