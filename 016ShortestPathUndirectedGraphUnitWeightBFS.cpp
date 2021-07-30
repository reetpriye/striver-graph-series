#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(N) -> For dis array
// O(N) -> For queue

// Time complexity: O(N+E)
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
    vector<int> adj[n];
    while(m--) {
        // To take edge inputs
        int u; // Initial node
        int v; // Final node
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> dis(n, INT_MAX);
    queue<int> q;
    q.push(0);
    dis[0] = 0;
    while(!q.empty()) {
        int fr = q.front();
        q.pop();
        for(int it: adj[fr]) {
            if(dis[it] > dis[fr]+1) {
                dis[it] = dis[fr] + 1;
                q.push(it);
            }
        }
    }

    for(int i=0; i<n; i++) {
        cout << 0 << "->" << i << ": " << dis[i] << "\n";
    }
    return 0;
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  9
Enter number of edges:  11
Enter the edges
0 1
1 3
3 0
1 2
2 6
6 5
5 4
4 3
6 7
7 8
6 8
0->0: 0
0->1: 1
0->2: 2
0->3: 1
0->4: 2
0->5: 3
0->6: 3
0->7: 4
0->8: 4
*/