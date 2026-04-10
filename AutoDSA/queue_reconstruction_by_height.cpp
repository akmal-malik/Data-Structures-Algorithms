// Problem: Queue Reconstruction by Height
// ------------------------------------------------------------
// Problem Description:
// Given a list of people, reconstruct the queue in such a way that each person 
// is at the position determined by their height. If two people have the same height,
// the shorter one should be positioned in front of the taller one.
// Each person is represented as a pair (h, k), where h is the height and k is the number
// of people in front of this person who have a height greater than or equal to h.
// ------------------------------------------------------------
// Approach: Greedy Algorithm
// Sort people first by their heights in descending order. If two people have the same 
// height, sort them by k values in ascending order. Then, insert each person into the 
// result queue at position k.
// This ensures that taller people are placed before shorter people, and within each 
// group of people with the same height, they are ordered by their k values.
// ------------------------------------------------------------
// Time Complexity: O(n^2), where n is the number of people. The insertion operation in a 
// vector takes linear time, and we perform this for all n people.
// Space Complexity: O(n), used for storing the result queue.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        // Sort by height in descending order. If heights are the same, sort by k in ascending order
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
        });
        
        // Insert each person into the result queue at position k
        vector<vector<int>> queue;
        for (const auto& p : people) {
            queue.insert(queue.begin() + p[1], p);
        }
        
        return queue;
    }
};