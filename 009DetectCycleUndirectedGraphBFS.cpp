#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(2*N) -> For queue of type pair<int, int>
// O(N) -> For visited array

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

bool isCycle(int node, vector<int> adj[], vector<int> &vis) {

    queue<pair<int, int>> q; // To store [node, parent]
    q.push({node, -1});
    vis[node] = true;

    while(!q.empty()) {
        int fr = q.front().first;
        int par = q.front().second;
        q.pop();

        for(int it: adj[fr]) {
            if(!vis[it]) {
                vis[it] = true;
                q.push({it, fr});
            }
            else if(it!=par)
                return true;
        }
    }
    return false;
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
    vector<int> vis(n, false);

    bool isCyclePresent = false;
    for(int i=0; i<n; i++) {
        if(!vis[i] and isCycle(i, adj, vis)) {
            isCyclePresent = true;
            break;
        }
    }
    if(isCyclePresent)
        cout << "Cycle is present\n";
    else
        cout << "Cycle is not present\n";

    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  8
Enter number of edges:  7
Enter the edges
0 2
2 3
1 4
4 5
5 6
6 7
7 4
Cycle is present

Enter number of nodes:  8
Enter number of edges:  6
Enter the edges
0 2
2 3
1 4
4 5
5 6
6 7
Cycle is not present
*/