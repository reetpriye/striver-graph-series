#include <bits/stdc++.h>

using namespace std;

// Spanning Tree: If we can convert a graph into a tree
// such that it contains all the N nodes with N-1 edges.
// Among all the spanning tree possible for a graph, the one
// which has the minimum cost of edges is known as minimum spanning
// tree[MST]

// Space complexity: O(N+2*E) + O(N) + O(N) + O(N) ~= O(N)
// O(N+2*E) -> For adj list[with weight]
// O(N) -> For key array
// O(N) -> For mst array
// O(N) -> For par array

// Time complexity: O(N+E) + O(N^2) ~= O(N^2)
// O(N^2) -> Traversing the key array to find min every time
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

int main() {
    int n; // Number of nodes
    int m; // Number of edges
    cout << "Enter number of nodes:\t";
    cin >> n;
    cout << "Enter number of edges:\t";
    cin >> m;
    cout << "Enter the edges\n";
    vector<pair<int, int>> adj[n];
    while(m--) {
        // To take edge inputs
        int u; // Initial node
        int v; // Final node
        int wt; // Weight
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> key(n, INT_MAX);
    vector<bool> mst(n, false);
    vector<int> par(n, -1);
    key[0] = 0;
    mst[0] = true;

    for(int cnt = 0; cnt < n-1; cnt++) {
        // Grabbing the lowest node from key array
        int min_key = INT_MAX;
        int min_idx;
        for(int i=0; i<n; i++) {
            if(!mst[i] and min_key > key[i]) {
                min_key = key[i];
                min_idx = i;
            }
        }
        
        mst[min_idx] = true;
        for(pair<int, int> it: adj[min_idx]) {
            if(!mst[it.first] and (key[it.first] > it.second)) {
                key[it.first] = it.second;
                par[it.first] = min_idx;
            }
        }
    }

    for(int i=0; i<n; i++) {
        if(par[i]==-1)
            cout << i << " is the root node\n";
        else    
            cout << "Parent of " << i << ": " << par[i] << "\n";
    }

    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  5
Enter number of edges:  6
Enter the edges
0 1 2
1 2 3
0 3 6
3 1 8
4 1 5
4 2 7
0 is the root node
Parent of 1: 0
Parent of 2: 1
Parent of 3: 0
Parent of 4: 1
*/