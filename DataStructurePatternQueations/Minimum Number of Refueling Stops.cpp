/*
🔥 Problem: Minimum Number of Refueling Stops

🧠 Approach:
We use a greedy strategy with a max heap.

Key Idea:
- Travel as far as possible with current fuel
- Push all reachable gas stations' fuel into a max heap
- When fuel runs out, refuel from the station with maximum fuel

Why Max Heap?
- Always pick the largest fuel first → maximize distance

⏱ Time Complexity: O(n log n)
📦 Space Complexity: O(n)
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // Max heap to store fuels of reachable stations
        priority_queue<int> maxHeap;

        int fuel = startFuel;   // Current fuel
        int stops = 0;          // Number of refuels
        int i = 0;              // Index for stations
        int n = stations.size();

        // Continue until we reach target
        while (fuel < target) {

            // Add all reachable stations to heap
            while (i < n && stations[i][0] <= fuel) {
                maxHeap.push(stations[i][1]);
                i++;
            }

            // If no stations available to refuel
            if (maxHeap.empty()) {
                return -1;
            }

            // Refuel with the largest available fuel
            fuel += maxHeap.top();
            maxHeap.pop();
            stops++;
        }

        return stops;
    }
};
