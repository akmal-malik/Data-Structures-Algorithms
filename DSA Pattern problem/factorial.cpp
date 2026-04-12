// Problem: Factorial
// ------------------------------------------------------------
// Problem Description:
// Given a non-negative integer n, return the factorial of n.
// The factorial of n (denoted as n!) is the product of all positive integers less than or equal to n.
// For example, factorial(5) = 5 * 4 * 3 * 2 * 1 = 120.
// ------------------------------------------------------------
// Approach: Iterative
// This approach uses an iterative method to calculate the factorial. 
// It starts with a result of 1 and multiplies it by each integer from 1 to n.
// ------------------------------------------------------------
// Time Complexity: O(n)
// The algorithm iterates through the loop n times, where n is the input number.
// Space Complexity: O(1)
// The space complexity is constant as it only uses a single variable to store the result.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; ++i) {
            result *= i;
        }
        return result;
    }
};