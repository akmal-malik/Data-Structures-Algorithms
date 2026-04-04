// Problem: Strongly connected components
// ------------------------------------------------------------
// Problem Description:
// A directed graph is strongly connected if there is a path from any vertex to every other vertex.
// The task is to find all the strongly connected components in a given graph.
// ------------------------------------------------------------
// Approach: Kosaraju's Algorithm
// It consists of two DFS traversals. First, we perform a DFS traversal and store the finish times (or postorder numbers) of vertices. Then, we reverse the directions of all edges and again do DFS based on the order of finish times obtained in step 1.
// ------------------------------------------------------------
// Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges.
// Space Complexity: O(V + E) for storing the graph and stack space used during DFS traversal.
// ------------------------------------------------------------
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visited(n, false);
        stack<int> s;

        // Step 1: DFS traversal and store finish times
        for(auto edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }
        dfs(0, adj, visited, s);

        // Step 2: Reverse the graph
        vector<vector<int>> revAdj(n);
        for(int i = 0; i < n; ++i) {
            for(auto j : adj[i]) {
                revAdj[j].push_back(i);
            }
        }

        // Step 3: DFS traversal on the reversed graph
        visited.assign(n, false);
        vector<vector<int>> scc;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(visited[node]) continue;
            vector<int> component;
            dfsHelper(node, revAdj, visited, component);
            scc.push_back(component);
        }

        return scc;
    }

private:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& s) {
        visited[node] = true;
        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfs(neighbor, adj, visited, s);
            }
        }
        s.push(node);
    }

    void dfsHelper(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& component) {
        visited[node] = true;
        component.push_back(node);
        for(auto neighbor : adj[node]) {
            if(!visited[neighbor]) {
                dfsHelper(neighbor, adj, visited, component);
            }
        }
    }
};