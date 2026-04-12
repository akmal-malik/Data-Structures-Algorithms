// Problem: Furthest Building
// ------------------------------------------------------------
// Problem Description:
// You are given an integer array heights representing the heights of buildings. You are also given an integer bricks and an integer ladders.
// Starting from building 0, you can either climb one or two steps at a time or use a ladder to move between any two buildings.
// Return the furthest building index you can reach.
// ------------------------------------------------------------
// Approach: Min-Heap (Priority Queue)
// Use a min-heap to keep track of the smallest jumps that are made using bricks. If at any point, the height difference exceeds the available bricks, replace the smallest jump with a ladder instead.
// ------------------------------------------------------------
// Time Complexity: O(n log k), where n is the number of buildings and k is the number of ladders
// Space Complexity: O(k)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int> pq; // Min-heap to store jump sizes that use bricks
        for (int i = 1; i < heights.size(); ++i) {
            int diff = heights[i] - heights[i - 1];
            if (diff > 0) {
                pq.push(-diff); // Store negative values to simulate min-heap using max-heap
                bricks -= diff;
                if (bricks < 0 && !pq.empty()) {
                    bricks += -pq.top(); // Replace the smallest jump with a ladder
                    pq.pop();
                    ladders--;
                }
                if (ladders < 0) return i - 1; // If no more ladders are available, return the current index
            }
        }
        return heights.size() - 1;
    }
};