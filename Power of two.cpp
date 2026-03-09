// Problem: Power of Two
// ------------------------------------------------------------
// Given an integer n, return true if it is a power of two.
// Otherwise, return false.
//
// An integer n is a power of two if there exists an integer x
// such that:
//
//      n == 2^x
//
// Example 1:
// Input: n = 1
// Output: true
// Explanation: 2^0 = 1
//
// Example 2:
// Input: n = 16
// Output: true
// Explanation: 2^4 = 16
//
// Example 3:
// Input: n = 3
// Output: false
//
// Constraints:
// -2^31 <= n <= 2^31 - 1
//
// ------------------------------------------------------------
// Approach: Bit Manipulation
//
// Key Observation:
// Powers of two contain exactly ONE set bit in binary.
//
// Examples:
// 1  -> 0001
// 2  -> 0010
// 4  -> 0100
// 8  -> 1000
//
// The trick:
//
//      n & (n - 1)
//
// removes the lowest set bit.
//
// If n is a power of two:
//
//      n & (n - 1) == 0
//
// Also we must ensure n > 0.
//
// ------------------------------------------------------------
// Time Complexity: O(1)
// Space Complexity: O(1)
// ------------------------------------------------------------

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0) return false;
        return (n & (n - 1)) == 0;
    }
};
