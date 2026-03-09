// Problem: Subarray sum equals k
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// ------------------------------------------------------------
// Approach: Prefix Sum and Hash Map
// We can use the concept of prefix sums. Let prefixSum[i] be the sum of elements from index 0 to i-1.
// The sum of a subarray from index i to j (inclusive) is prefixSum[j+1] - prefixSum[i].
// We are looking for subarrays where prefixSum[j+1] - prefixSum[i] = k.
// Rearranging this, we get prefixSum[i] = prefixSum[j+1] - k.
// We can iterate through the array, calculating the current prefix sum. For each current prefix sum, we check if there was a previous prefix sum such that (current_prefix_sum - k) exists in our hash map.
// The hash map will store the frequency of each prefix sum encountered so far.
// If current_prefix_sum - k is found in the map, it means there are 'map[current_prefix_sum - k]' subarrays ending at the current index whose sum is k.
// We initialize the map with {0: 1} to handle cases where the subarray starts from index 0.
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
        unordered_map<int, int> prefix_sum_counts;
        prefix_sum_counts[0] = 1; // To handle subarrays that start from index 0

        for (int num : nums) {
            current_sum += num;
            if (prefix_sum_counts.count(current_sum - k)) {
                count += prefix_sum_counts[current_sum - k];
            }
            prefix_sum_counts[current_sum]++;
        }

        return count;
    }
};