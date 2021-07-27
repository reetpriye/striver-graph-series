#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(N) -> Auxiliary space for stack
// O(N) -> For visited array

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

void dfs(int node, vector<int> adj[], vector<bool> &vis) {
    
    vis[node] = true;
    cout << node << " ";

    for(int it: adj[node]) {
        if(!vis[it])
            dfs(it, adj, vis);
    }
}

int main() {
    int n; // Number of nodes
    int m; // Number of edges
    cout << "Enter number of nodes:\t";
    cin >> n;
    cout << "Enter number of edges:\t";
    cin >> m;
    cout << "Enter the edges\n";
    vector<int> adj[n];
    while(m--) {
        // To take edge inputs
        int u; // Initial node
        int v; // Final node
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);

    cout << "DFS: ";
    for(int i=0; i<n; i++) {
        if(!vis[i])
            dfs(i, adj, vis);
    }
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  7
Enter number of edges:  6
Enter the edges
0 1
1 2
2 4
4 6
6 1
3 5
DFS: 0 1 2 4 6 3 5
*/