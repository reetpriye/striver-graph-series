#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) + O(N) + O(N) ~= O(N)
// O(N+E) -> For storing edges
// O(N) -> For vis array
// O(N) -> For tin array
// O(N) -> For low array
// O(N) -> Auxiliary space for stack

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

void dfs(int node, int parent, vector<bool> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[]) {
    vis[node] = true;
    tin[node] = low[node] = timer++;
    for(auto it: adj[node]) {
        if(it==parent) continue;

        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj);
            low[node] = min(low[node], low[it]);
            if(low[it] > tin[node])
                cout << node << " " << it << "\n";
        
        }
        else
            low[node] = min(low[node], tin[it]);
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

    vector<int> tin(n, -1);
    vector<int> low(n, -1);
    vector<bool> vis(n, false);

    int timer = 0;
    cout << "Bridges: \n";
    for(int i=0; i<n; i++) {
        if(!vis[i])
            dfs(i, -1, vis, tin, low, timer, adj);
    }
    cout << "\n";
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  12
Enter number of edges:  14
Enter the edges
0 1
1 2
2 3
0 3
3 4
4 5
5 8
5 6
6 7
8 7
7 9
9 10
10 11
9 11
Bridges: 
7 9
4 5
3 4
*/