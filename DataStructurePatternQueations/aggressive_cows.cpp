// Problem: Aggressive cows
// ------------------------------------------------------------
// Problem Description:
// Given N cows and K stalls on a straight line, the task is to assign stalls to cows such that the minimum distance between any two cows is maximized.
// ------------------------------------------------------------
// Approach: Binary Search
// Binary search on the maximum possible minimum distance between cows.
// For each mid value, check if it's possible to place all cows such that the minimum distance is at least mid.
// If possible, try a larger mid; otherwise, try a smaller mid.
// ------------------------------------------------------------
// Time Complexity: O(N log D), where N is the number of stalls and D is the maximum possible distance between stalls.
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPossible(vector<int>& stalls, int K, int mid) {
        int cowCount = 1;
        int lastPosition = stalls[0];
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPosition >= mid) {
                cowCount++;
                lastPosition = stalls[i];
                if (cowCount == K) {
                    return true;
                }
            }
        }
        return false;
    }
    
    int maxDistance(vector<int>& stalls, int K) {
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();
        int s = 0;
        int e = stalls[n - 1] - stalls[0];
        int ans = -1;
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (isPossible(stalls, K, mid)) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
        return ans;
    }
};