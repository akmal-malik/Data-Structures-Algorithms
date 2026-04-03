// Problem: Is graph bipartite
// ------------------------------------------------------------
// Problem Description:
// Given an undirected graph, return true if and only if it is bipartite.
// Recall that a graph is bipartite if we can split its set of nodes into two independent subsets A and B such that every edge in the graph connects a node in subset A and a node in subset B.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// We use DFS to attempt to color the graph using two colors. If at any point we find an adjacent node with the same color, the graph is not bipartite.
// ------------------------------------------------------------
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
// Space Complexity: O(V) for storing the visited array and recursion stack
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1); // Initialize color array with -1 (uncolored)

        for (int i = 0; i < n; ++i) {
            if (color[i] == -1 && !dfs(graph, color, i, 0)) {
                return false;
            }
        }

        return true;
    }

private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
        color[node] = c; // Color the current node

        for (int neighbor : graph[node]) {
            if (color[neighbor] == -1) {
                if (!dfs(graph, color, neighbor, 1 - c)) {
                    return false;
                }
            } else if (color[neighbor] == c) {
                return false;
            }
        }

        return true;
    }
};