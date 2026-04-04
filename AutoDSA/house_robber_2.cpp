// Problem: House robber 2
// ------------------------------------------------------------
// Problem Description:
// You are a professional robber planning to rob houses along a street. 
// Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
// Note: Houses in a circle are adjacent to each other. That is, the first and last houses are considered adjacent.
// ------------------------------------------------------------
// Approach: Dynamic Programming with Space Optimization
// Use two variables to keep track of the maximum money robbed up to the current house without robbing the previous one (excluding the first house) and including the previous one.
// For the circular case, consider two scenarios:
// 1. Rob the first house but not the last.
// 2. Do not rob the first house.
// Take the maximum of these two scenarios as the final result.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1) - Using constant extra space for variables
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        auto robLinear = [&](int start, int end) {
            int prev2 = 0, prev1 = 0;
            for (int i = start; i <= end; ++i) {
                int temp = max(prev1, prev2 + nums[i]);
                prev2 = prev1;
                prev1 = temp;
            }
            return prev1;
        };
        
        // Rob houses from the first to second last
        int robFirstLast = robLinear(0, n - 2);
        // Rob houses from the second to last (excluding the first)
        int robSecondLast = robLinear(1, n - 1);
        
        return max(robFirstLast, robSecondLast);
    }
};