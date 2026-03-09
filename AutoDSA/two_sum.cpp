// Problem: Two Sum
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// ------------------------------------------------------------
// Approach: Hash Map
// We can use a hash map (unordered_map in C++) to store the complement of each number encountered so far. For each number `nums[i]`, we calculate its complement `complement = target - nums[i]`. We then check if this `complement` exists as a key in our hash map. If it does, it means we've found the two numbers that sum up to the target, and we return the current index `i` and the index stored for the complement in the hash map. If the complement is not found, we add the current number `nums[i]` as a key to the hash map with its index `i` as the value, to be used for future lookups.
// ------------------------------------------------------------
// Time Complexity: O(n)
// We iterate through the array once. Hash map lookups and insertions take average O(1) time.
// Space Complexity: O(n)
// In the worst case, the hash map might store all elements of the input array.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (num_map.count(complement)) {
                return {num_map[complement], i};
            }
            num_map[nums[i]] = i;
        }
        return {}; // Should not reach here given problem constraints
    }
};