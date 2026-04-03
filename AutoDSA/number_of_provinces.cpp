// Problem: Number of provinces
// ------------------------------------------------------------
// Problem Description:
// Given an n x n adjacency matrix representing a network of cities, where the value at index (i, j) is 1 if there is a direct flight from city i to city j, and 0 otherwise. Your task is to determine the total number of distinct provinces in the network. A province is defined as a group of directly or indirectly connected cities.
// ------------------------------------------------------------
// Approach: Depth-First Search (DFS)
// Perform DFS on each city that has not been visited yet. Each DFS traversal will cover all cities in one province.
// ------------------------------------------------------------
// Time Complexity: O(n^2), where n is the number of cities. We potentially visit each edge once.
// Space Complexity: O(n) for the stack used during DFS and the visited array.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int provinces = 0;
        
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(isConnected, visited, i);
                ++provinces;
            }
        }
        
        return provinces;
    }

private:
    void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int city) {
        visited[city] = true;
        for (int j = 0; j < isConnected.size(); ++j) {
            if (isConnected[city][j] == 1 && !visited[j]) {
                dfs(isConnected, visited, j);
            }
        }
    }
};