// Problem: Min cost to connect all points
// ------------------------------------------------------------
// Problem Description:
// Given an array of points where each point is represented as a pair (xi, yi), return the minimum cost to connect all these points using the Minimum Spanning Tree (MST) approach. The cost to connect two points is defined as the Manhattan distance between them.
// ------------------------------------------------------------
// Approach: Kruskal's Algorithm
// Use Kruskal's algorithm to find the MST of the given graph, where each point is a node and an edge exists between every pair of points with its corresponding Manhattan distance as the weight. Sort all edges in ascending order and add them to the MST if they don't form a cycle.
// ------------------------------------------------------------
// Time Complexity: O(E log E), where E is the number of edges (n(n-1)/2).
// Space Complexity: O(V + E), for storing the graph and union-find data structure.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<pair<int, pair<int, int>>> edges;
        
        // Create all edges
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int cost = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                edges.push_back({cost, {i, j}});
            }
        }
        
        // Sort edges by cost
        sort(edges.begin(), edges.end());
        
        // Union-Find data structure
        vector<int> parent(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        
        auto find = [&](int x) {
            if (parent[x] != x)
                parent[x] = find(parent[x]);
            return parent[x];
        };
        
        int mst_cost = 0, edges_used = 0;
        for (const auto& edge : edges) {
            int u = edge.second.first, v = edge.second.second;
            int pu = find(u), pv = find(v);
            if (pu != pv) {
                parent[pu] = pv;
                mst_cost += edge.first;
                ++edges_used;
                if (edges_used == n - 1)
                    break;
            }
        }
        
        return mst_cost;
    }
};