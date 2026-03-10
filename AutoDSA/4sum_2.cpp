// Problem: 4sum 2
// ------------------------------------------------------------
// Problem Description:
// Given an array of integers, find all unique quadruplets in the array which gives the sum of target.
// ------------------------------------------------------------
// Approach: Two-pointer technique
// Use a hash map to store the sum of two numbers and their indices. Then, iterate through the array and use two-pointer technique to find pairs that add up to the target minus the current sum of two numbers.
// ------------------------------------------------------------
// Time Complexity: O(n^3)
// Space Complexity: O(n^2)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        unordered_map<int, vector<pair<int, int>>> mp;
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                mp[nums[i] + nums[j]].push_back({i, j});
            }
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i + 1; j < nums.size(); ++j) {
                int complement = target - (nums[i] + nums[j]);
                if (mp.find(complement) != mp.end()) {
                    for (auto& p : mp[complement]) {
                        if (p.second > j) {
                            result.push_back({nums[i], nums[j], nums[p.first], nums[p.second]});
                        }
                    }
                }
            }
        }
        
        sort(result.begin(), result.end());
        auto last = unique(result.begin(), result.end());
        result.erase(last, result.end());
        
        return result;
    }
};