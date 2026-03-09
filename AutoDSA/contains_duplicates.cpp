// Problem: Contains Duplicates
// ------------------------------------------------------------
// Problem Description:
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// ------------------------------------------------------------
// Approach: Hash Set (unordered_set)
// We can iterate through the array and use a hash set (unordered_set in C++) to keep track of the elements we have encountered so far. For each element, we check if it already exists in the hash set. If it does, it means we have found a duplicate, and we can immediately return true. If it doesn't, we add the element to the hash set. If we iterate through the entire array without finding any duplicates, we return false.
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