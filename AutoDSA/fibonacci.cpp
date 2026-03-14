// Problem: Fibonacci
// ------------------------------------------------------------
// Problem Description:
// The Fibonacci sequence is defined by the recurrence relation:
// F(n) = F(n-1) + F(n-2), where F(0) = 0 and F(1) = 1.
// Given an integer n, return the n-th Fibonacci number.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We use a bottom-up approach to store the Fibonacci numbers
// from 0 to n in an array to avoid redundant calculations.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;
        vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};