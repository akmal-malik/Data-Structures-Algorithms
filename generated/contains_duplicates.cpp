// Problem: Contains Duplicates
// ------------------------------------------------------------
// Problem Description:
// Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.
// ------------------------------------------------------------
// Approach: Hash Set (std::unordered_set)
// We can iterate through the input array `nums`. For each element, we check if it's already present in a hash set (unordered_set). If it is, we've found a duplicate and can immediately return `true`. If it's not in the set, we insert it. If we iterate through the entire array without finding any duplicates, we return `false`.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen;
        for (int num : nums) {
            if (seen.count(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};