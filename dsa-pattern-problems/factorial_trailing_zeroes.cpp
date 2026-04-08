// Problem: Factorial trailing zeroes
// ------------------------------------------------------------
// Problem Description:
// Given an integer n, return the number of trailing zeroes in n!.
// Note: Your solution should be in logarithmic time complexity.
// ------------------------------------------------------------
// Approach: Legendre's formula
// The number of trailing zeroes in n! is determined by the number of pairs of factors 2 and 5. Since there are always more factors of 2 than factors of 5, the number of trailing zeroes is determined by the number of factors of 5.
// We can find the number of factors of 5 by summing up the quotients of n divided by 5, 25, 125, etc.
// Time Complexity: O(log₅(n))
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while (n >= 5) {
            n /= 5;
            count += n;
        }
        return count;
    }
};