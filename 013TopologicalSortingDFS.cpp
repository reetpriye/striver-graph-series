#include <bits/stdc++.h>

using namespace std;

// Topological sorting: Linear ordering of vertices such
// that if there is an edge u->v, u appears before v
// in that ordering

// Space complexity: O(N+E) + O(N) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(2*N) -> For vis array
// O(N) -> For stack
// O(N) -> Auxiliary space for stack

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

void topoSort(int node, vector<int> adj[], vector<bool> &vis, stack<int> &st) {

    vis[node] = true;

    for(int it: adj[node]) {
        if(!vis[it])
            topoSort(it, adj, vis, st);
    }

    st.push(node);
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
    }
    vector<bool> vis(n, false);
    stack<int> st;

    for(int i=0; i<n; i++) {
        if(!vis[i])
            topoSort(i, adj, vis, st);
    }

    cout << "Topological Sorting: ";
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  6
Enter number of edges:  6
Enter the edges
5 0
4 0
4 1
3 1
2 3
5 2
Topological Sorting: 5 4 2 3 1 0
*/