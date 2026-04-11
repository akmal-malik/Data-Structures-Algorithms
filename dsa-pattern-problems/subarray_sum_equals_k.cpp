// Problem: Subarray sum equals k
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
// ------------------------------------------------------------
// Approach: Hash Map (Prefix Sum)
// The idea is to use a hash map to store the cumulative sum up to each index. For each element in the array, we calculate the prefix sum and check if there exists a previous prefix sum such that their difference equals k.
// ------------------------------------------------------------
// Time Complexity: O(n), where n is the number of elements in the array.
// Space Complexity: O(n) for storing the prefix sums in the hash map.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> sumFreq;
        sumFreq[0] = 1; // Base case: a prefix sum of 0 has occurred once
        int currentSum = 0, count = 0;
        
        for (int num : nums) {
            currentSum += num;
            if (sumFreq.find(currentSum - k) != sumFreq.end()) {
                count += sumFreq[currentSum - k];
            }
            sumFreq[currentSum]++;
        }
        
        return count;
    }
};