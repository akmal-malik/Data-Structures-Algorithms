// Problem: Dungeon Game
// ------------------------------------------------------------
// Problem Description:
// The demons had captured the princess and imprisoned her in the bottom-right corner of a dungeon. 
// The dungeon consists of M x N rooms, with each room containing -100 to 100 integers that represent its
// strength. If a hero enters a room, his health point will be reduced by the room's value (negative values 
// decrease health, positive values increase it). The hero starts with 1 unit of health and needs at least 
// 1 HP when he leaves the dungeon.
// Determine the minimum initial health required to rescue the princess.
// ------------------------------------------------------------
// Approach: Dynamic Programming
// We can use dynamic programming to solve this problem by starting from the bottom-right corner and moving backwards. 
// The value in each cell represents the minimum health needed for a hero entering that cell to survive until the end of the dungeon.
// ------------------------------------------------------------
// Time Complexity: O(M*N)
// Space Complexity: O(N) (we can optimize space by using only one-dimensional DP array)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        // Initialize the DP array
        vector<int> dp(n + 1, INT_MAX);
        dp[n - 1] = 1; // Minimum health needed at the exit
        
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int minHealth = min(dp[j], dp[j + 1]);
                if (minHealth > dungeon[i][j]) {
                    dp[j] = minHealth - dungeon[i][j];
                } else {
                    dp[j] = 1;
                }
            }
        }
        
        return max(1, dp[0]); // Ensure the hero has at least 1 HP
    }
};