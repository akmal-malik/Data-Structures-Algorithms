// Problem: Minimum refueling stops
// ------------------------------------------------------------
// Problem Description:
// Given a car with an initial fuel capacity and a list of gas stations along a route, 
// determine the minimum number of refueling stops required to reach the destination. 
// If it's not possible to reach the destination, return -1.
// Each station provides a certain amount of fuel, and you can stop at any station 
// to refuel an unlimited amount of times. The car consumes one unit of fuel per mile.
// ------------------------------------------------------------
// Approach: Greedy Algorithm with Priority Queue
// Use a priority queue (max-heap) to keep track of the available fuels from the stations we have passed but not yet refueled at.
// As we drive, if the car runs out of fuel, we refuel from the largest available fuel in the priority queue.
// If we can't refuel and still need more fuel, return -1 as it's impossible to reach the destination.
// ------------------------------------------------------------
// Time Complexity: O(n log n) due to sorting and priority queue operations
// Space Complexity: O(n) for storing fuel amounts in the priority queue
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<int>& stations) {
        int n = stations.size();
        int stops = 0;
        long currentFuel = startFuel;
        priority_queue<int> pq;
        
        for (int i = 0; i <= n; ++i) {
            while (!pq.empty() && currentFuel < (i == n ? target : stations[i])) {
                currentFuel += pq.top();
                pq.pop();
                stops++;
            }
            
            if (currentFuel < (i == n ? target : stations[i])) return -1;
            
            if (i < n) pq.push(stations[i] - (i > 0 ? stations[i-1] : 0));
        }
        
        return stops;
    }
};