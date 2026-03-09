// Problem: Subarray sum equals k
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// ------------------------------------------------------------
// Approach: Prefix Sum with HashMap
// We can use a hash map to store the frequency of prefix sums encountered so far.
// For each element, we calculate the current prefix sum. If (current_prefix_sum - k) exists in the hash map, it means there is a subarray ending at the current position whose sum is k. We add the frequency of (current_prefix_sum - k) to our result.
// We also store the current_prefix_sum in the hash map, incrementing its count if it already exists.
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
        int currentSum = 0;
        unordered_map<int, int> prefixSumCount;
        prefixSumCount[0] = 1; // To handle cases where the subarray starts from the beginning

        for (int num : nums) {
            currentSum += num;
            if (prefixSumCount.count(currentSum - k)) {
                count += prefixSumCount[currentSum - k];
            }
            prefixSumCount[currentSum]++;
        }

        return count;
    }
};