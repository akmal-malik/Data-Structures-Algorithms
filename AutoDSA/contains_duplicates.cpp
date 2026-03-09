// Problem: Contains Duplicates
// ------------------------------------------------------------
// Problem Description:
// Given an integer array nums, return true if any value appears at least twice in the array and return false if every element is distinct.
// ------------------------------------------------------------
// Approach: Hash Set
// Use a hash set to track elements we have seen. If we encounter an element that is already in the set, return true. If we finish iterating through the array without finding duplicates, return false.
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
            if (seen.find(num) != seen.end()) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};