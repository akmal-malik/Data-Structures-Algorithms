// Problem: Cheapest flights within k stops
// ------------------------------------------------------------
// Problem Description:
// Given n cities labeled from 0 to n - 1 and n * (n - 1) directed edges representing flights between different cities, each with a cost. Find the cheapest price from city 0 to city n - 1 with at most k stops.
// The graph is represented as an array of arrays where flights[i] = [fromi, toi, pricei], indicating there's a flight from city fromi to city toi with cost pricei.
// Note that the number of edges in the graph is in the range [0, n * (n - 1)], and k is always non-negative.
// ------------------------------------------------------------
// Approach: Dijkstra's Algorithm
// Use Dijkstra's algorithm to find the shortest path within k stops. Maintain a priority queue to explore nodes with the smallest distance first while keeping track of the number of stops taken so far.
// ------------------------------------------------------------
// Time Complexity: O((V + E) * log V), where V is the number of vertices (cities) and E is the number of edges (flights).
// Space Complexity: O(V + E) for storing the graph and priority queue.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int k) {
        vector<pair<int, int>> adj[n];
        for (auto& flight : flights) {
            adj[flight[0]].push_back({flight[1], flight[2]});
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0}); // {cost, current_city, stops}
        
        while (!pq.empty()) {
            auto [cost, city, stops] = pq.top();
            pq.pop();
            
            if (city == n - 1) return cost; // Reached destination
            
            if (stops > k) continue; // More than k stops, skip
            for (auto& neighbor : adj[city]) {
                int nextCity = neighbor.first;
                int nextCost = neighbor.second;
                pq.push({cost + nextCost, nextCity, stops + 1});
            }
        }
        
        return -1; // No valid path within k stops
    }
};