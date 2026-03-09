// Problem: Counting Bits
// ------------------------------------------------------------
// Given an integer n, return an array ans of length n + 1
// where ans[i] represents the number of set bits (1s)
// in the binary representation of i.
//
// Example 1:
// Input: n = 2
// Output: [0,1,1]
//
// Explanation:
// 0 -> 0
// 1 -> 1
// 2 -> 10
//
// Example 2:
// Input: n = 5
// Output: [0,1,1,2,1,2]
//
// Explanation:
// 0 -> 0
// 1 -> 1
// 2 -> 10
// 3 -> 11
// 4 -> 100
// 5 -> 101
//
// Constraints:
// 0 <= n <= 10^5
//
// Follow-up:
// Can you solve it in O(n) time without using built-in
// functions like __builtin_popcount?
//
// ------------------------------------------------------------
// Approach: Dynamic Programming + Bit Manipulation
//
// Key observation:
//
//      bits(i) = bits(i >> 1) + (i & 1)
//
// Explanation:
// i >> 1 removes the last bit of i
// (i & 1) checks whether the last bit is 1
//
// Example:
// i = 5 (101)
//
// i >> 1 = 2 (10)
// i & 1 = 1
//
// bits(5) = bits(2) + 1 = 2
//
// Using this relation we build results from 0 → n.
//
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            ans[i] = ans[i >> 1] + (i & 1);
        }

        return ans;
    }
};
