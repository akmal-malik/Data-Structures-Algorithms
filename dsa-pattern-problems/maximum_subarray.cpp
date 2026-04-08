// Problem: Maximum subarray
// ------------------------------------------------------------
// Problem Description:
// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
// Example:
// Input: nums = [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// ------------------------------------------------------------
// Approach: Kadane's Algorithm
// This algorithm maintains a running sum of the subarray and updates the maximum sum found so far. If the running sum becomes negative, it is reset to zero.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_current = nums[0];
        int max_global = nums[0];
        
        for (int i = 1; i < nums.size(); ++i) {
            max_current = max(nums[i], max_current + nums[i]);
            if (max_current > max_global) {
                max_global = max_current;
            }
        }
        
        return max_global;
    }
};