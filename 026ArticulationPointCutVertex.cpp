#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) + O(N) + O(N) + O(N) + O(N) ~= O(N)
// O(N+E) -> For storing edges
// O(N) -> For par array
// O(N) -> For vis array
// O(N) -> For tin array
// O(N) -> For low array
// O(N) -> For isArticulation array
// O(N) -> Auxiliary space for stack

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

void dfs(int node, int par, vector<bool> &vis, vector<int> &tin, vector<int> &low, int &timer, vector<int> adj[], vector<bool> &isArticulation) {

    vis[node] = true;
    tin[node] = low[node] = timer++;
    int child = 0;
    for(int it: adj[node]) {
        if(it == par) continue;

        if(!vis[it]) {
            dfs(it, node, vis, tin, low, timer, adj, isArticulation);
            low[node] = min(low[node], low[it]);
            if(low[it] >= tin[node] and par != -1)
                isArticulation[node] = true;
        }
        else
            low[node] = min(low[node], tin[it]);
    }

    if(par == -1 and child > 1)
        isArticulation[node] = true;
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
    vector<bool> isArticulation(n, false);
    int timer = 0;
    for(int i=0; i<n; i++) {
        if(!vis[i])
            dfs(i, -1, vis, tin, low, timer, adj, isArticulation);
    }

    cout << "Articulation points: ";
    for(int i=0; i<n; i++) {
        if(isArticulation[i])
            cout << i << " ";
    }
    cout << "\n";
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
Articulation points: 3 4 5 7 9 
*/