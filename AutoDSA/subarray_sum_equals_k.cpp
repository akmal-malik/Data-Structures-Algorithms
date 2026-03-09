// Problem: Subarray sum equals k
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer k, return the number of continuous subarrays whose sum equals k.
// ------------------------------------------------------------
// Approach: Prefix Sum with Hash Map
// Use a hash map to store the cumulative sum up to each index. For each element, check if the current cumulative sum minus k exists in the hash map.
// If it does, it means there is a subarray that sums to k. Update the count accordingly.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count = 0, sum = 0;
        unordered_map<int, int> sumMap;
        sumMap[0] = 1; // Initialize with sum 0 having one occurrence

        for (int num : nums) {
            sum += num; // Update cumulative sum
            if (sumMap.find(sum - k) != sumMap.end()) {
                count += sumMap[sum - k]; // Increment count if (sum - k) exists in map
            }
            sumMap[sum]++; // Add current sum to map
        }

        return count;
    }
};