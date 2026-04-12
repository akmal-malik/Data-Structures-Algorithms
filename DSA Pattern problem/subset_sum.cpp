// Problem: Subset sum
// ------------------------------------------------------------
// Problem Description:
// Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with a sum equal to the given sum.
// ------------------------------------------------------------
// Approach: Dynamic Programming (DP)
// We use a DP array where dp[i][j] indicates whether a subset with sum j can be formed from the first i elements of the array. 
// The solution fills this DP table by iterating through each element and updating the possible sums that can be formed.
// ------------------------------------------------------------
// Time Complexity: O(n * sum)
// Space Complexity: O(sum)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool subsetSum(vector<int>& nums, int sum) {
        int n = nums.size();
        vector<bool> dp(sum + 1, false);
        dp[0] = true; // Base case: There's always a subset with sum 0 (empty subset)

        for (int i = 0; i < n; ++i) {
            for (int j = sum; j >= nums[i]; --j) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
        }

        return dp[sum];
    }
};