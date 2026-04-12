// Problem: Jump game
// ------------------------------------------------------------
// Problem Description:
// You are given an array of non-negative integers nums. You are initially positioned at the first index of the array. Each element in the array represents your maximum jump length at that position. Determine if you can reach the last index.
// For example, for input nums = [2,3,1,1,4], the output should be true because you can jump to the last index (index 4) from the first index.
// ------------------------------------------------------------
// Approach: Greedy Algorithm
// This solution uses a greedy approach where we keep track of the farthest point that can be reached as we iterate through the array. If at any point, our current position is greater than or equal to this farthest point, we return false. Otherwise, we update the farthest point.
// ------------------------------------------------------------
// Time Complexity: O(n)
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        
        return true;
    }
};