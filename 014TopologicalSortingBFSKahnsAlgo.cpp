#include <bits/stdc++.h>

using namespace std;

// Topological sorting: Linear ordering of vertices such
// that if there is an edge u->v, u appears before v
// in that ordering

// Space complexity: O(N+E) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(N) -> For Indegree array
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
    }
    vector<int> inDegree(n);

    for(int i=0; i<n; i++) {
        for(int j: adj[i])
            inDegree[j]++;
    }

    cout << "Topological Sorting: ";

    queue<int> q;
    for(int i=0; i<n; i++) {
        if(inDegree[i]==0)
            q.push(i);
    }

    while(!q.empty()) {
        int fr = q.front();
        q.pop();

        cout << fr << " ";

        for(int it: adj[fr]) {
            inDegree[it]--;
            if(inDegree[it]==0)
                q.push(it);
        }
    }

    return 0;
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
Topological Sorting: 4 5 0 2 3 1
*/