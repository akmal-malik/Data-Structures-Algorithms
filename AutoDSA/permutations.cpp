// Problem: Permutations
// ------------------------------------------------------------
// Problem Description:
// Given an array nums of distinct integers, return all the possible permutations of nums. You can return the answer in any order.
// ------------------------------------------------------------
// Approach: Backtracking
// Use backtracking to generate all permutations. At each step, choose a number from the remaining numbers and add it to the current permutation. Recursively generate permutations for the remaining numbers. Backtrack by removing the last number added to return to the previous state.
// ------------------------------------------------------------
// Time Complexity: O(n!)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);
        backtrack(nums, current, used, result);
        return result;
    }
private:
    void backtrack(const vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            used[i] = true;
            current.push_back(nums[i]);
            backtrack(nums, current, used, result);
            current.pop_back();
            used[i] = false;
        }
    }
};