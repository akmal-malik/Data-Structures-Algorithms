// Problem: Heaps (19 problems)
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums, find the length of the longest subsequence such that all its elements are strictly increasing.
// Example 1:
// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:
// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:
// Input: nums = [7,7,7,7,7,7,7]
// Output: 1
// ------------------------------------------------------------
// Approach: Dynamic Programming with Binary Search
// Use a vector to store the smallest possible tail values of all increasing subsequences. 
// Iterate through the input array and for each number, use binary search to find the position it should replace or insert in the vector.
// If the number is larger than the last element in the vector, append it. Otherwise, update the existing element at the found position.
// The size of the vector at the end will be the length of the longest increasing subsequence.
// ------------------------------------------------------------
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;
        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num);
            } else {
                *it = num;
            }
        }
        return tails.size();
    }
};