// Problem: Contains Duplicates
// ------------------------------------------------------------
// Problem Description:
// Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.
// ------------------------------------------------------------
// Approach: Sorting
// Sort the input array. After sorting, if there are any duplicate elements, they will be adjacent to each other. Iterate through the sorted array and compare each element with its next element. If any adjacent pair is equal, it means a duplicate exists.
// ------------------------------------------------------------
// Time Complexity: O(N log N) due to sorting.
// Space Complexity: O(1) or O(log N) depending on the sorting algorithm used by the standard library (in-place sort vs. merge sort).
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i+1]) {
                return true;
            }
        }
        return false;
    }
};