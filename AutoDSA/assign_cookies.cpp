// Problem: Assign cookies
// ------------------------------------------------------------
// Problem Description:
// We are given a number of children and the amount of cookie each child has. 
// We also have an array of cookie sizes that are available to distribute.
// The goal is to maximize the number of satisfied children, where a child is satisfied if they can get at least one cookie that meets their size requirement.
// Each cookie can only be given to one child and a child can only eat one cookie. 
// ------------------------------------------------------------
// Approach: Greedy algorithm
// Sort both the children's greed factors and the available cookies in ascending order. 
// Iterate through each child, trying to give them the smallest possible cookie that meets their size requirement.
// If no suitable cookie is found for a child, they remain unsatisfied.
// This approach ensures that we maximize the number of satisfied children by always trying to meet the smallest unmet need first.
// ------------------------------------------------------------
// Time Complexity: O(n log n + m log m), where n is the number of children and m is the number of cookies. 
// Sorting both arrays takes O(n log n) and O(m log m) time respectively, while iterating through them takes linear time.
// Space Complexity: O(1)
// Only a constant amount of extra space is used.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child = 0;
        for (int i = 0; i < s.size() && child < g.size(); ++i) {
            if (s[i] >= g[child]) {
                ++child;
            }
        }
        
        return child;
    }
};