#include <bits/stdc++.h>
using namespace std;

bool dfs(int u, vector<vector<int>>& adj, vector<int>& visited, int count, int N) {
    if (count == N) return true;  

    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = 1;
            if (dfs(v, adj, visited, count + 1, N))
                return true;
            visited[v] = 0; 
        }
    }

    return false;
}

bool hasHamiltonianPath(int N, vector<vector<int>>& adj) {

    for (int start = 0; start < N; start++) {
        vector<int> visited(N, 0);
        visited[start] = 1;

        if (dfs(start, adj, visited, 1, N))
            return true;
    }
    return false;
}

int main() {
    int N = 5;
    vector<vector<int>> adj(N);
    vector<pair<int,int>> edges = {
        {0,1}, {1,2}, {2,3}, {3,4}
    };

    for (auto &e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }

    if (hasHamiltonianPath(N, adj))
        cout << "Hamiltonian Path Exists\n";
    else
        cout << "No Hamiltonian Path\n";

    return 0;
}
