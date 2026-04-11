// Problem: Graphs (30 problems)
// ------------------------------------------------------------
// Problem Description:
// Given a connected acyclic graph, perform a topological sort of the vertices.
// The graph is represented using an adjacency list where each key is a vertex and its value is a vector of adjacent vertices.
// ------------------------------------------------------------
// Approach: Kahn's Algorithm
// Use BFS to process nodes with zero in-degree, decrementing the in-degree of neighboring nodes until all nodes are processed.
// ------------------------------------------------------------
// Time Complexity: O(V + E)
// Space Complexity: O(V + E)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topologicalSort(vector<vector<int>>& graph, int V) {
        vector<int> in_degree(V, 0);
        vector<int> result;
        
        // Calculate in-degree for each vertex
        for (int i = 0; i < V; ++i) {
            for (int neighbor : graph[i]) {
                in_degree[neighbor]++;
            }
        }
        
        // Queue to store vertices with zero in-degree
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (in_degree[i] == 0) {
                q.push(i);
            }
        }
        
        // Process vertices in topological order
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            result.push_back(u);
            
            for (int v : graph[u]) {
                if (--in_degree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        return result;
    }
};