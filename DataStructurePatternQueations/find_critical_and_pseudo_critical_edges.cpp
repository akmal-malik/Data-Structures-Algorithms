// Problem: Find critical and pseudo critical edges
// ------------------------------------------------------------
// Problem Description:
// Given a weighted connected graph with n vertices numbered from 0 to n - 1, and an array of edges where each edge has two nodes and a weight. 
// A critical edge is defined as an edge that must be included in all minimum spanning trees (MSTs) of the graph, while a pseudo-critical edge is one that can be removed without changing the set of edges forming any MST.
// The function should return a vector with two lists: the first list contains the indices of critical edges and the second list contains the indices of pseudo-critical edges.
// ------------------------------------------------------------
// Approach: Kruskal's Algorithm with Union-Find
// We will use Kruskal's algorithm to find all MSTs. To determine if an edge is critical, we temporarily exclude it from our consideration and check if we can still form a spanning tree with the remaining edges. If not, this edge is critical. For pseudo-critical edges, we include them in every possible way and again try to form MSTs.
// Time Complexity: O(E * log E) for sorting + O(E * (V * alpha(V))) for each edge check using Union-Find
// Space Complexity: O(E + V)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int m = edges.size();
        for (int i = 0; i < m; ++i) edges[i].push_back(i);
        
        sort(edges.begin(), edges.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[2] < b[2];
        });
        
        auto find = [&](int x, vector<int>& parent) {
            if (parent[x] != x) parent[x] = find(parent[x], parent);
            return parent[x];
        };
        
        auto unionSet = [&](int x, int y, vector<int>& parent) {
            int rootX = find(x, parent), rootY = find(y, parent);
            if (rootX != rootY) parent[rootY] = rootX;
        };
        
        auto kruskal = [&](bool includeEdge, int excludeEdge) {
            vector<int> parent(n);
            iota(parent.begin(), parent.end(), 0);
            
            int cost = 0, edgesUsed = 0;
            if (includeEdge != -1) {
                unionSet(edges[includeEdge][0], edges[includeEdge][1], parent);
                cost += edges[includeEdge][2];
                ++edgesUsed;
            }
            
            for (int i = 0; i < m && edgesUsed < n - 1; ++i) {
                if (excludeEdge == i) continue;
                int u = edges[i][0], v = edges[i][1], w = edges[i][2];
                if (find(u, parent) != find(v, parent)) {
                    unionSet(u, v, parent);
                    cost += w;
                    ++edgesUsed;
                }
            }
            
            return edgesUsed == n - 1 && cost;
        };
        
        vector<int> criticalEdges, pseudoCriticalEdges;
        
        for (int i = 0; i < m; ++i) {
            if (!kruskal(i, -1)) criticalEdges.push_back(edges[i][3]);
        }
        
        for (int i = 0; i < m; ++i) {
            int costWithoutEdge = kruskal(-1, i);
            if (costWithoutEdge && kruskal(true, i)) pseudoCriticalEdges.push_back(edges[i][3]);
        }
        
        return {criticalEdges, pseudoCriticalEdges};
    }
};