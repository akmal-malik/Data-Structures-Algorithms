// Problem: Search in rotated sorted array
// ------------------------------------------------------------
// Problem Description:
// Given a sorted array of distinct integers that has been rotated 
// at some pivot unknown to you beforehand, write a function 
// to find the index of a target value if it is in the array, 
// otherwise, return -1. You must write an algorithm with O(log n) 
// runtime complexity.
// ------------------------------------------------------------
// Approach: Binary Search
// Perform binary search to find the target value in the rotated 
// sorted array. Check if the left half or the right half is 
// sorted and decide which half to continue the search.
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
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[left] <= nums[mid]) {
                if (nums[left] <= target && target < nums[mid]) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[right]) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};