// Problem: House robber
// ------------------------------------------------------------
// Problem Description:
// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
// Given an integer array nums representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// Use dynamic programming to solve this problem. We maintain a DP array where dp[i] represents the maximum amount of money that can be robbed from houses up to i. The recurrence relation is dp[i] = max(dp[i-1], nums[i] + dp[i-2]), which means we either skip the current house or rob it and add its value to the maximum amount robbed until two houses before.
// ------------------------------------------------------------
// Time Complexity: O(n)
// We only need a single pass through the array, so the time complexity is linear.
// Space Complexity: O(n)
// We use an additional array of size n for the DP table, so the space complexity is also linear. However, this can be optimized to O(1) by using two variables to keep track of the previous two values in the DP array instead of storing the entire array.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.empty()) return 0;
        if (nums.size() == 1) return nums[0];
        
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < nums.size(); ++i) {
            dp[i] = max(dp[i-1], nums[i] + dp[i-2]);
        }
        
        return dp[nums.size()-1];
    }
};