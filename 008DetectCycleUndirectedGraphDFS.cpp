#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(N) -> Auxiliary space for stack
// O(N) -> For visited array

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

bool isCycle(int node, int parent, vector<int> adj[], vector<int> &vis) {

    vis[node] = true;

    for(int it: adj[node]) {
        if(!vis[it]) {
            if(isCycle(it, node, adj, vis))
                return true;
        }
        // If visited but is not equal to parent
        else if(it!=parent)
            return true;
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
        if(!vis[i] and isCycle(i, -1, adj, vis)) {
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