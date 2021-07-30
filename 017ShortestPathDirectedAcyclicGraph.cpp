#include <bits/stdc++.h>

using namespace std;

// Find topo sort first -> then calculate distance

// Space complexity: O(N+2*E) + O(2*N) + O(N) + O(N) + O(N) ~= O(N)
// For topo sort
// O(N+2*E) -> For adj list[with weight]
// O(2*N) -> For vis array
// O(N) -> For stack
// O(N) -> Auxiliary space for stack
// For calculating distance
// O(N) -> For dis array

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

void topo_sort(int node, vector<pair<int, int>> adj[], stack<int> &st, vector<bool> &vis) {

    vis[node] = true;

    for(pair<int, int> it: adj[node]) {
        if(!vis[it.first])
            topo_sort(it.first, adj, st, vis);
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
    vector<pair<int, int>> adj[n];
    while(m--) {
        // To take edge inputs
        int u; // Initial node
        int v; // Final node
        int w; // Weight
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
    }
    int src;
    cout << "Enter source node: ";
    cin >> src;

    vector<bool> vis(n, false);
    stack<int> st;
    for(int i=0; i<n; i++) {
        if(!vis[i])
            topo_sort(i, adj, st, vis);
    }

    vector<int> dis(n, INT_MAX);
    dis[src] = 0;
    while(!st.empty()) {
        int fr = st.top();
        st.pop();
        if(dis[fr]!=INT_MAX) {
            for(pair<int, int> it: adj[fr]) {
                if(dis[fr] + it.second < dis[it.first]) {
                    dis[it.first] = dis[fr] + it.second;
                }
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << src << "->" << i << ": ";
        if(dis[i]==INT_MAX)
            cout << "INF\n";
        else cout << dis[i] << "\n";
    }

    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  6
Enter number of edges:  7
Enter the edges
0 1 2
1 2 3
2 3 6
0 4 1
4 2 2
4 5 4
5 3 1
Enter source node: 0
0->0: 0
0->1: 2
0->2: 3
0->3: 6
0->4: 1
0->5: 5
*/