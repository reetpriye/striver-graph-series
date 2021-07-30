#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(2*N) ~= O(N)
// O(N+E) -> For adj list
// O(N) -> For dis array
// O(2*N) -> For priority queue

// Time complexity: O(N+ElogN)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall
// and logN to get topmost element in priority queue

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
    int src;
    cout << "Enter src node: ";
    cin >> src;

    // pair -> {dist, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dis(n, INT_MAX);
    pq.push({0, src});
    dis[src] = 0;
    while(!pq.empty()) {
        int fr = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        
        for(pair<int, int> it: adj[fr]) {
            if(dis[it.first] > dis[fr] + it.second) {
                dis[it.first] = dis[fr] + it.second;
                pq.push({dis[it.first], it.first});
            }
        }
    }
    for(int i=0; i<n; i++) {
        cout << src << "->" << i << ": " << dis[i] << "\n";
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
1 4 5
4 2 1
2 3 3
3 0 1
1 2 4
Enter src node: 0 
0->0: 0
0->1: 2
0->2: 4
0->3: 1
0->4: 5
*/