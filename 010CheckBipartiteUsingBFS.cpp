#include <bits/stdc++.h>

using namespace std;

// Bipartite Graph: A graph which can be colored using two colors
// such that no two adjacent nodes have same color

// Space complexity: O(N+E) + O(N) + O(N) ~= O(N)
// O(N+E) -> For adj list
// O(N) -> For queue
// O(N) -> For colors array

// Time complexity: O(N+E)
// N is the time taken for visiting N nodes and
// E is for travelling through adjacent nodes overall

bool isBipartite(int node, vector<int> adj[], vector<int> &colors) {
    
    queue<int> q; // To store nodes
    q.push(node);
    colors[node] = 1;

    while(!q.empty()) {

        int fr = q.front();
        q.pop();
        for(int it: adj[fr]) {
            if(colors[it] == -1) {
                colors[fr] == 1 ? colors[it] = 0 : colors[it] = 1;
                q.push(it);
            }
            else if(colors[it]==colors[fr])
                return false;
        }

    }


    return true;
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

    bool isGraphBipartite = true;
    vector<int> colors(n, -1);

    for(int i=0; i<n; i++) {
        if(colors[i]==-1 and !isBipartite(i, adj, colors)) {
            isGraphBipartite = false;
            break;
        }        
    }

    if(isGraphBipartite)
        cout << "Graph is bipartite\n";
    else 
        cout << "Graph is not bipartite\n";
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  8
Enter number of edges:  8
Enter the edges
0 1
1 2
2 3
3 4
4 7
7 1
4 5
5 6
Graph is not bipartite

Enter number of nodes:  8
Enter number of edges:  8
Enter the edges
0 1
1 2
2 3
3 4
4 5
5 6
6 1
4 7
Graph is bipartite
*/