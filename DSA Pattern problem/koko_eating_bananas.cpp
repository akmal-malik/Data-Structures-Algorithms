// Problem: Koko eating bananas
// ------------------------------------------------------------
// Problem Description:
// Koko loves to eat bananas. There are n piles of bananas, and she can eat at most one pile per hour. The i-th pile has piles[i] bananas. Koko can only eat bananas from one pile at a time. Given an integer h, which is the number of hours Koko has to eat all the bananas, return the minimum integer k such that she can eat all the bananas within h hours.
// ------------------------------------------------------------
// Approach: Binary Search
// Binary search on the number of bananas Koko can eat per hour.
// The lower bound is 1 (Koko can eat at least one banana per hour), and the upper bound is the maximum number of bananas in any pile (Koko can eat all bananas from one pile in one hour if she is allowed to).
// For each mid in binary search, calculate the total hours Koko needs to eat all bananas if she eats mid bananas per hour. If the total hours are less than or equal to h, it means Koko can eat all bananas within h hours if she eats mid bananas per hour, so we try a smaller number of bananas (right = mid). Otherwise, we try a larger number of bananas (left = mid + 1).
// The binary search continues until left is equal to right, which is the minimum number of bananas Koko can eat per hour to finish all bananas within h hours.
// ------------------------------------------------------------
// Time Complexity: O(nlogm), where n is the number of piles and m is the maximum number of bananas in any pile.
// Space Complexity: O(1)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1, right = *max_element(piles.begin(), piles.end());
        while (left < right) {
            int mid = (left + right) / 2;
            int hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // Equivalent to ceil(p / mid)
            }
            if (hours <= h) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};