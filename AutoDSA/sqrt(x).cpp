// Problem: Sqrt(x)
// ------------------------------------------------------------
// Problem Description:
// Given a non-negative integer x, compute and return the square root of x.
// Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
// ------------------------------------------------------------
// Approach: Binary Search
// The square root of a number x can be found using binary search between 0 and x. For each midpoint, we calculate its square and compare it with x to adjust the search range.
// ------------------------------------------------------------
// Time Complexity: O(log x)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1) return x;
        int left = 1, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid == x / mid) return mid;
            else if (mid < x / mid) left = mid + 1;
            else right = mid - 1;
        }
        return right;
    }
};