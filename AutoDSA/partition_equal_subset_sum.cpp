// Problem: Partition equal subset sum
// ------------------------------------------------------------
// Problem Description:
// Given a non-empty array nums containing only positive integers, 
// determine if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
// A non-empty subset means at least one element in each subset.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// The problem can be reduced to a 0/1 knapsack problem where we decide for each number whether to include it or not 
// to form a sum that is half of the total sum of the array. We use a boolean DP table dp[i][j] 
// where dp[i][j] is true if there's a subset with sum j using the first i elements.
// ------------------------------------------------------------
// Time Complexity: O(n * sum/2)
// Space Complexity: O(sum/2)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (totalSum % 2 != 0) return false; // If sum is odd, it cannot be partitioned into two equal subsets
        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true; // Base case: there's always a subset with sum 0 (empty subset)
        
        for (int num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }
        
        return dp[target];
    }
};