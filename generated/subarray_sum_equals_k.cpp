// Problem: Subarray sum equals k
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer k, return the total number of continuous subarrays whose sum equals to k.
// ------------------------------------------------------------
// Approach: Prefix Sum and Hash Map
// We can use the concept of prefix sums. A prefix sum `P[i]` is the sum of elements from index 0 to `i-1`.
// The sum of a subarray from index `j` to `i-1` can be calculated as `P[i] - P[j]`.
// We are looking for subarrays where `P[i] - P[j] = k`. This can be rewritten as `P[j] = P[i] - k`.
// As we iterate through the array and calculate the current prefix sum `current_sum` (which corresponds to `P[i]` in the equation),
// we check if `current_sum - k` exists in a hash map. The hash map will store the frequencies of prefix sums encountered so far.
// If `current_sum - k` is found in the map, it means there are `map[current_sum - k]` previous prefix sums that, when subtracted from the `current_sum`, result in `k`.
// We add this count to our total result. We also update the frequency of the `current_sum` in the hash map.
// We initialize the map with `{0, 1}` to handle the case where a prefix sum itself equals `k` (meaning the subarray starts from index 0).
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
        prefix_sum_counts[0] = 1; // Initialize for subarrays starting from index 0

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