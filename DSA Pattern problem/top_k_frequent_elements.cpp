// Problem: Top k frequent elements
// ------------------------------------------------------------
// Problem Description:
// Given a non-empty array of integers, return the k most frequent elements.
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Your algorithm's time complexity must be better than O(n log n), where n is the array size.
// ------------------------------------------------------------
// Approach: Bucket Sort
// Use a bucket to store numbers with the same frequency. The index of the bucket represents the frequency,
// and each bucket can contain a list of numbers that have the same frequency.
// Traverse the input array and fill in the buckets accordingly. Then, starting from the highest frequency,
// collect elements from the buckets until we have k elements.
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> frequencyMap;
        for (int num : nums) {
            frequencyMap[num]++;
        }

        vector<vector<int>> buckets(nums.size() + 1);
        for (const auto& pair : frequencyMap) {
            buckets[pair.second].push_back(pair.first);
        }

        vector<int> result;
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {
            result.insert(result.end(), buckets[i].begin(), buckets[i].end());
        }

        return result;
    }
};