// Problem: Critical connections
// ------------------------------------------------------------
// Problem Description:
// Given a graph represented as an adjacency list, return all the critical connections (also called bridges) in the network. A critical connection is a connection that, if removed, would make some nodes unable to reach other nodes.
// ------------------------------------------------------------
// Approach: Tarjan's Algorithm
// Use Tarjan's algorithm to find articulation points and bridges in the graph. An edge is a bridge if it does not lie on any cycle in the graph. Articulation points are vertices that remove which increases the number of connected components.
// ------------------------------------------------------------
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
// Space Complexity: O(V)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> disc(n), low(n), parent(n, -1);
        vector<bool> visited(n);
        vector<vector<int>> bridges;
        
        function<void(int)> tarjan = [&](int u) {
            static int time = 0;
            disc[u] = low[u] = ++time;
            visited[u] = true;
            
            for (int v : connections[u]) {
                if (!visited[v]) {
                    parent[v] = u;
                    tarjan(v);
                    low[u] = min(low[u], low[v]);
                    
                    // Check if the edge is a bridge
                    if (low[v] > disc[u]) {
                        bridges.push_back({u, v});
                    }
                } else if (v != parent[u]) {
                    low[u] = min(low[u], disc[v]);
                }
            }
        };
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                tarjan(i);
            }
        }
        
        return bridges;
    }
};