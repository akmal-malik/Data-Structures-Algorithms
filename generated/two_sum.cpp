// Problem: Two Sum
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// ------------------------------------------------------------
// Approach: Hash Map
// We can use a hash map (unordered_map in C++) to store the elements of the array and their corresponding indices.
// Iterate through the array. For each element, calculate the complement (target - current_element).
// Check if the complement exists in the hash map.
// If it exists, we have found the two numbers, and we return their indices (the current index and the index stored in the hash map for the complement).
// If the complement does not exist, add the current element and its index to the hash map.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
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