// Problem: Coin change
// ------------------------------------------------------------
// Problem Description:
// Given an integer array coins[] representing coins of different denominations and an integer amount representing a total amount of money, return the fewest number of coins that you need to make up that amount. If it is impossible to make up that amount, return -1.
// You may assume that you have an infinite number of each kind of coin.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// The problem can be solved using dynamic programming where we build a table dp[] in which dp[i] will hold the minimum number of coins required to make sum i. Initialize all entries as infinite except dp[0] which is 0. For each coin, update the dp array for sums greater than or equal to the value of the coin.
// ------------------------------------------------------------
// Time Complexity: O(amount * n), where amount is the target amount and n is the number of coin denominations
// Space Complexity: O(amount)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                if (dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], dp[i - coin] + 1);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};