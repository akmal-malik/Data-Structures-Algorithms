// Problem: Contains Duplicates
// ------------------------------------------------------------
// Problem Description:
// Given an integer array nums, return true if any value appears at least twice in the array and false if every element is distinct.
// ------------------------------------------------------------
// Approach: Hash Set
// Use a hash set to keep track of the elements we've seen as we iterate through the array. If we encounter an element that's already in the set, we return true. If we finish iterating without finding any duplicates, we return false.
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