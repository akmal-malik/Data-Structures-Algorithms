// Problem: Network delay time
// ------------------------------------------------------------
// Problem Description:
// Given a directed graph with n nodes labeled from 1 to n and some edges with travel times, 
// find the minimum time it takes for all nodes to receive a signal. If it is not possible, return -1.
// Example:
// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2
// Explanation: The signal travels from node 2 to node 1 (time 1) and then from node 2 to node 3 (time 1), 
// and finally from node 3 to node 4 (time 1). So the minimum time is 2.
// ------------------------------------------------------------
// Approach: Dijkstra's Algorithm
// Use a priority queue to always expand the least costly path first. Maintain an array of minimum times for each node.
// Time Complexity: O((E + V) log V), where E is the number of edges and V is the number of vertices (nodes).
// Space Complexity: O(E + V)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> graph[n];
        for(auto &time : times){
            graph[time[0] - 1].push_back({time[1] - 1, time[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[k - 1] = 0;
        pq.push({0, k - 1});

        while (!pq.empty()) {
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            if (d > dist[u]) continue;

            for(auto &neighbor : graph[u]){
                int v = neighbor.first;
                int weight = neighbor.second;

                if(dist[v] > dist[u] + weight){
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = *max_element(dist.begin(), dist.end());
        return (maxTime == INT_MAX) ? -1 : maxTime;
    }
};