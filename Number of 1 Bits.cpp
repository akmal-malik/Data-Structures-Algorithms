// Problem: Number of 1 Bits (Hamming Weight)
// ------------------------------------------------------------
// Given a positive integer n, return the number of set bits
// (1s) in its binary representation.
//
// Example 1:
// Input: n = 11
// Binary: 1011
// Output: 3
//
// Example 2:
// Input: n = 128
// Binary: 10000000
// Output: 1
//
// Example 3:
// Input: n = 2147483645
// Output: 30
//
// ------------------------------------------------------------
// Approach: Brian Kernighan’s Algorithm
//
// Key Observation:
// The operation
//
//      n & (n - 1)
//
// removes the lowest set bit from n.
//
// Example:
// n = 1011
// n-1 = 1010
//
// 1011
// 1010
// ----
// 1010   (lowest set bit removed)
//
// So we repeatedly apply this operation until n becomes 0
// and count how many times it happens.
//
// ------------------------------------------------------------
// Time Complexity: O(number of set bits)
// Worst case: O(32)
//
// Space Complexity: O(1)
// ------------------------------------------------------------

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;

        while(n) {
            n = n & (n - 1);
            count++;
        }

        return count;
    }
};
