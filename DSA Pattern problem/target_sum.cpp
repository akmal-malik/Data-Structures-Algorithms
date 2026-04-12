// Problem: Target sum
// ------------------------------------------------------------
// Problem Description:
// You are given a non-empty array nums containing only positive integers.
// You can assign each integer in the array either a '+' or '-' sign. The task is to find the number of ways to assign signs to the elements such that the sum of the resulting array is equal to a target value.
// For example, if the input array is [1, 1, 1, 1] and the target is 3, there are two ways to achieve this: [+1, +1, +1, -1] and [+1, +1, -1, +1].
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use a dynamic programming approach where dp[i][j] represents the number of ways to obtain a sum 'i' using the first 'j' elements of the array. The solution iterates through each element and updates the possible sums.
// ------------------------------------------------------------
// Time Complexity: O(n * target), where n is the length of the input array
// Space Complexity: O(target)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totalSum || (totalSum + target) % 2 != 0) return 0;
        
        int subsetSum = (totalSum + target) / 2;
        vector<int> dp(subsetSum + 1, 0);
        dp[0] = 1; // There's one way to get sum 0: by choosing no elements
        
        for (int num : nums) {
            for (int j = subsetSum; j >= num; --j) {
                dp[j] += dp[j - num];
            }
        }
        
        return dp[subsetSum];
    }
};