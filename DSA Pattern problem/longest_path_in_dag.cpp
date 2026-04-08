// Problem: Longest path in dag
// ------------------------------------------------------------
// Problem Description:
// Given a directed acyclic graph (DAG), find the longest path from any node to any other node. A path's length is the number of edges in the path.
// ------------------------------------------------------------
// Approach: Topological Sort + Dynamic Programming
// We first perform topological sort on the DAG. Then, we use dynamic programming where dp[i] represents the longest path ending at vertex i. For each vertex, we update its dp value by considering all its neighbors and adding an edge to the neighbor.
// ------------------------------------------------------------
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
// Space Complexity: O(V + E) for storing the graph and the dp array
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPath(vector<vector<int>>& graph, vector<int>& indegree) {
        int V = graph.size();
        vector<int> dp(V, 0);
        
        queue<int> q;
        for (int i = 0; i < V; ++i) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            
            for (int v : graph[u]) {
                dp[v] = max(dp[v], dp[u] + 1);
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        
        int result = 0;
        for (int i = 0; i < V; ++i) {
            result = max(result, dp[i]);
        }
        
        return result;
    }

    int longestPathInDAG(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> indegree(V, 0);
        
        // Calculate the in-degree of each vertex
        for (int i = 0; i < V; ++i) {
            for (int j : graph[i]) {
                indegree[j]++;
            }
        }
        
        return longestPath(graph, indegree);
    }
};