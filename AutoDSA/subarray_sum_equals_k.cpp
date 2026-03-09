// Problem: Subarray sum equals k
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// ------------------------------------------------------------
// Approach: Prefix Sum with Hash Map
// We can use a hash map to store the frequency of prefix sums encountered so far. For each element, we calculate the current prefix sum. If `current_sum - k` exists in the hash map, it means there's a subarray ending at the current position with a sum equal to k. We add the frequency of `current_sum - k` to our count. We also update the frequency of the `current_sum` in the hash map.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0;
        int current_sum = 0;
        unordered_map<int, int> prefix_sum_freq;
        prefix_sum_freq[0] = 1; // Base case: an empty prefix sum (sum 0) occurs once.

        for (int num : nums) {
            current_sum += num;
            if (prefix_sum_freq.count(current_sum - k)) {
                count += prefix_sum_freq[current_sum - k];
            }
            prefix_sum_freq[current_sum]++;
        }

        return count;
    }
};