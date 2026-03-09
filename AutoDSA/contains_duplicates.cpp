// Problem: Contains Duplicates
// ------------------------------------------------------------
// Problem Description:
// Given an integer array `nums`, return `true` if any value appears at least twice in the array, and return `false` if every element is distinct.
// ------------------------------------------------------------
// Approach: Hash Set
// We can use a hash set (unordered_set in C++) to keep track of the elements we have encountered so far. Iterate through the array. For each element, check if it's already present in the hash set. If it is, then we have found a duplicate, and we can return `true`. If it's not present, add it to the hash set. If we iterate through the entire array without finding any duplicates, we return `false`.
// ------------------------------------------------------------
// Time Complexity: O(n)
// We iterate through the array once. Hash set insertion and lookup operations take average O(1) time.
// Space Complexity: O(n)
// In the worst case, if all elements are distinct, the hash set will store all n elements.
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