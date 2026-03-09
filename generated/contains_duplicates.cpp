
// Problem: Two Sum
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers nums and an integer target,
// return indices of the two numbers such that they add up to target.
//
// Example 1:
// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
//
// Example 2:
// Input: nums = [3,2,4], target = 6
// Output: [1,2]
//
// Constraints:
// 2 <= nums.length <= 10^4
//
// ------------------------------------------------------------
// Approach: Hash Map
//
// Store numbers in a hashmap while iterating.
// For each element check if (target - current)
// exists in the map.
//
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------

#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;

    for(int i=0;i<nums.size();i++){
        int diff = target - nums[i];

        if(mp.count(diff))
            return {mp[diff], i};

        mp[nums[i]] = i;
    }

    return {};
}
