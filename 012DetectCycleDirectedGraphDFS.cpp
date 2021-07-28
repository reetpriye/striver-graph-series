#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(2*N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(2*N) -> For vis and visDfs array
// O(N) -> Auxiliary space for stack

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

bool isCycle(int node, vector<int> adj[], vector<bool> &vis, vector<bool> visDfs) {

    vis[node] = true;
    visDfs[node] = true;

    for(int it: adj[node]) {
        if(!vis[it]) {
            if(isCycle(it, adj, vis, visDfs))
                return true;
        }
        else if(visDfs[it])
            return true;
    }

    visDfs[node] = false;
    
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
    }

    vector<bool> vis(n, false);
    vector<bool> visDfs(n, false);
    bool isCyclePresent = false;
    
    for(int i=0; i<n; i++) {
        if(!vis[i] and isCycle(i, adj, vis, visDfs)) {
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
Enter number of nodes:  9
Enter number of edges:  10
Enter the edges
0 1
6 1
6 7
7 8
8 6
1 2
2 3
3 4
2 5
5 4
Cycle is present

Enter number of nodes:  9
Enter number of edges:  10
Enter the edges
0 1
6 1
6 7
6 8
7 8
1 2
2 5
5 4
2 3
3 4
Cycle is not present
*/