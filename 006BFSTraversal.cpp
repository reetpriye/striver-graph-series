#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(N) -> For queue
// O(N) -> For visited array

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

void bfs(int node, vector<int> adj[], vector<bool> &vis) {
    queue<int> q;
    q.push(node);
    vis[node] = true;

    while(!q.empty()) {
        int fr = q.front();
        cout << fr << " ";
        q.pop();
        for(int i: adj[fr]) {
            if(!vis[i]) {
                vis[i] = true;
                q.push(i);
            }
        }
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

    cout << "BFS: ";
    for(int i=0; i<n; i++) {
        if(!vis[i])
            bfs(i, adj, vis);
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
BFS: 0 1 2 6 4 3 5
*/