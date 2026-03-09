// Problem: Two Sum
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// ------------------------------------------------------------
// Approach: Hash Map
// We can use a hash map (unordered_map in C++) to store the numbers we have seen so far and their indices.
// For each number in the input array, we calculate the complement (target - current_number).
// If the complement exists in the hash map, it means we have found the two numbers that add up to the target.
// We then return the index of the complement from the hash map and the current index.
// If the complement is not found, we add the current number and its index to the hash map.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            numMap[nums[i]] = i;
        }
        return {}; // Should not reach here given the problem constraints
    }
};