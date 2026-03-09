// Problem: Two Sum
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
// You can return the answer in any order.
// ------------------------------------------------------------
// Approach: Hash Map
// We can use a hash map (unordered_map in C++) to store the elements of the array along with their indices.
// Iterate through the array. For each element, calculate the complement (target - current_element).
// Check if the complement exists in the hash map.
// If it exists, it means we have found the two numbers that add up to the target. Return the current index and the index of the complement stored in the hash map.
// If the complement does not exist, add the current element and its index to the hash map.
// ------------------------------------------------------------
// Time Complexity: O(n)
// We iterate through the array once. Hash map lookups and insertions are O(1) on average.
// Space Complexity: O(n)
// In the worst case, we might store all elements of the array in the hash map.
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
        return {}; // Should not reach here given problem constraints
    }
};