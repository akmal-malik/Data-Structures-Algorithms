// Problem: Longest consecutive sequence
// ------------------------------------------------------------
// Problem Description:
// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
// For example, given [100, 4, 200, 1, 3, 2], the longest consecutive elements sequence is [1, 2, 3, 4]. Therefore, its length is 4.
// ------------------------------------------------------------
// Approach: HashSet
// Insert all elements of the array into a hash set for O(1) average-time complexity for lookups.
// Iterate through the array, and for each number, check if it is the start of a sequence (i.e., the number before it is not in the set).
// If it is the start, count the length of the sequence by incrementing the number until it is not in the set.
// Keep track of the maximum sequence length.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(n)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longestStreak = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int currentNum = num;
                int currentStreak = 1;

                while (numSet.find(currentNum + 1) != numSet.end()) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }
        }

        return longestStreak;
    }
};