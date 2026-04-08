// Problem: Coin change 2
// ------------------------------------------------------------
// Problem Description:
// You are given an integer array coins representing coins of different denominations and an integer amount 
// representing a total amount of money. Return the number of combinations that make up that amount. If that amount 
// of money cannot be made up by any combination of the coins, return 0.
// You may assume that you have an infinite number of each kind of coin.
// Note: The problem assumes that the answer is a non-negative integer.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use a bottom-up dynamic programming approach. Let dp[i] be the number of combinations to make up amount i.
// We initialize dp[0] = 1 since there's one way to make the amount zero (using no coins).
// For each coin, we update dp for all amounts from the value of the coin up to the target amount.
// The state transition is dp[i] += dp[i - coin], which means that the number of ways to make amount i with a given 
// set of coins is equal to the sum of ways without considering the current coin (dp[i]) and the ways where we use at least one of the current coin (dp[i - coin]).
// ------------------------------------------------------------
// Time Complexity: O(amount * num_coins)
// Space Complexity: O(amount)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }
        
        return dp[amount];
    }
};