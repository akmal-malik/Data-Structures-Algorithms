// Problem: Revise completed topics weekly to retain patterns
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer target, return the number of non-empty subarrays whose sum is equal to target.
// A subarray is a contiguous part of an array.
// ------------------------------------------------------------
// Approach: Prefix Sum with Hash Map
// We use a prefix sum approach combined with a hash map to keep track of the frequency of prefix sums. This allows us to efficiently find the number of subarrays that sum to the target.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraySumTarget(vector<int>& nums, int target) {
        unordered_map<int, int> prefixSumCount;
        int prefixSum = 0, count = 0;
        
        for (int num : nums) {
            prefixSum += num;
            
            if (prefixSum == target) {
                count++;
            }
            
            if (prefixSumCount.find(prefixSum - target) != prefixSumCount.end()) {
                count += prefixSumCount[prefixSum - target];
            }
            
            prefixSumCount[prefixSum]++;
        }
        
        return count;
    }
};