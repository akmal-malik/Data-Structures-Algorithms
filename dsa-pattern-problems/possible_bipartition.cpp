// Problem: Possible bipartition
// ------------------------------------------------------------
// Problem Description:
// Given a set of N people (numbered 1, 2, ..., N), we want to split everyone into two groups. 
// We are given a list of pairs, where each pair represents a friendship between two people.
// The task is to determine if it's possible to split the people into two groups such that no two friends are in the same group.
// ------------------------------------------------------------
// Approach: Graph Bipartitioning
// Use Depth-First Search (DFS) to check if the graph formed by friendships is bipartite. 
// If a cycle is encountered with an odd length, it's not possible to bipartite the graph.
// ------------------------------------------------------------
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges
// Space Complexity: O(V + E)
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(N+1);
        for (auto& pair : dislikes) {
            graph[pair[0]].push_back(pair[1]);
            graph[pair[1]].push_back(pair[0]);
        }
        
        vector<int> color(N+1, -1); // -1 means uncolored, 0 and 1 represent two different colors
        
        for (int i = 1; i <= N; ++i) {
            if (color[i] == -1 && !dfs(graph, color, i, 0)) {
                return false;
            }
        }
        
        return true;
    }
    
private:
    bool dfs(vector<vector<int>>& graph, vector<int>& color, int node, int c) {
        color[node] = c;
        for (int neighbor : graph[node]) {
            if (color[neighbor] == color[node]) {
                return false;
            } else if (color[neighbor] == -1 && !dfs(graph, color, neighbor, 1-c)) {
                return false;
            }
        }
        return true;
    }
};