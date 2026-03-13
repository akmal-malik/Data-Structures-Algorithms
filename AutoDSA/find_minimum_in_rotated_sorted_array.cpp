// Problem: Find minimum in rotated sorted array
// ------------------------------------------------------------
// Problem Description:
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
// Find the minimum element.
// You may assume no duplicate exists in the array.
// ------------------------------------------------------------
// Approach: Binary Search
// The array is rotated, so we can use binary search to find the minimum element.
// If the middle element is less than the last element, the minimum is in the left half.
// Otherwise, the minimum is in the right half.
// ------------------------------------------------------------
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};