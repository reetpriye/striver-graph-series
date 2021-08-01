#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) + O(N) + O(N+E) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(2*N) -> For vis array
// O(N) -> For stack
// O(N) -> Auxiliary space for stack
// O(N+E) -> Transpose array
// O(N) -> Auxiliary space for stack(revDFS)

// Time complexity: O(N+E) + O(N+E) + O(N+E) ~= O(N+E)
// O(N+E) -> For topo sort
// O(N+E) -> For taking transpose
// O(N+E) -> For performing DFS again

// Strongly Connected Component(SCC): If we start from any node we can
// reach all the other nodes present in that component.

// ALGO:
// 1. Sort all the nodes a/c to the finishing time[Topo Sort]
// 2. Take transpose of the graph
// 3. Do the DFS call a/c to the finishing time

void topo_sort(int node, vector<int> adj[], stack<int> &st, vector<bool> &vis) {
    vis[node] = true;

    for(int it: adj[node]) {
        if(!vis[it])
            topo_sort(it, adj, st, vis);
    }
    
    st.push(node);
}

void revDfs(int node, vector<int> transpose[], vector<bool> &vis) {
    cout << node << " ";
    vis[node] = true;
    for(int it: transpose[node]) {
        if(!vis[it])
            revDfs(it, transpose, vis);
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes:\t";
    cin >> n;
    cout << "Enter number of edges:\t";
    cin >> m;
    vector<int> adj[n];
    cout << "Enter the elements:\n";
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Perform the topo sort
    stack<int> st;
    vector<bool> vis(n, false);
    for(int i=0; i<n; i++) {
        if(!vis[i])
            topo_sort(i, adj, st, vis);
    }

    // Create the transpose adjacency list
    vector<int> transpose[n];
    for(int i=0; i<n; i++) {
        vis[i] = false;
        for(auto it: adj[i])
            transpose[it].push_back(i);   
    }

    while(!st.empty()) {
        int node = st.top();
        st.pop();
        if(!vis[node]) {
            cout << "SCC: ";
            revDfs(node, transpose, vis);
            cout << "\n";
        }
    }
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  5
Enter number of edges:  5
Enter the elements:
0 1
1 2
2 0
1 3
3 4
SCC: 0 2 1 
SCC: 3
SCC: 4
*/