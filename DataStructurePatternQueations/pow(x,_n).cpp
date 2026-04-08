// Problem: Pow(x, n)
// ------------------------------------------------------------
// Problem Description:
// Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
// ------------------------------------------------------------
// Approach: Binary Exponentiation
// Binary Exponentiation is a fast algorithm to calculate powers. It reduces the time complexity to O(log n) by reducing the number of multiplications needed.
// ------------------------------------------------------------
// Time Complexity: O(log n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        if (n < 0) return 1 / myPow(x, -n);
        if (n % 2 == 0) return myPow(x * x, n / 2);
        return x * myPow(x * x, n / 2);
    }
};