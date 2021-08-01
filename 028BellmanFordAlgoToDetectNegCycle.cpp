#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N+E) + O(N) ~= O(N)
// O(N+E) -> For storing edges
// O(N) -> For dist array

// Time complexity: O((N-1)*E)
// N-1 -> No. of nodes - 1
// E -> No. of edges

// Bellman Ford's algo helps to find shortest possible distance
// to all other nodes.
// It can also work for undirected graph(make it directed).
// This algo doesn't helps to get shortest distance in case of 
// negative cycle. But can detect that as well.

// Algo: Relax all the edges N-1 times[N->No. of nodes]
#define INF 100000

struct Node{
    int u;
    int v;
    int wt;
    Node(int first, int second, int weight) {
        u = first;
        v = second;
        wt = weight;
    }
};

int main() {
    int n, m;
    cout << "Enter number of nodes:\t";
    cin >> n;
    cout << "Enter number of edges:\t";
    cin >> m;
    vector<Node> edges;
    cout << "Enter the elements:\n";
    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Node(u, v, wt));
    }
    int src;
    cout << "Enter the source node: ";
    cin >> src;
    vector<int> dis(n, INF);
    dis[src] = 0;
    for(int i=0; i<n-1; i++) {
        for(auto it: edges) {
            if(dis[it.u] + it.wt < dis[it.v])
                dis[it.v] = dis[it.u] + it.wt;
        }
    }

    bool negCyclePresent = false;
    
    for(auto it: edges) {
        if(dis[it.u] + it.wt < dis[it.v]) {
            negCyclePresent = true;
            break;
        }
    }

    if(negCyclePresent) {
        cout << "Negative cycle is present\n";
        return 0;
    }

    for(int i=0; i<n; i++)
        cout << src << " -> " << i << ": " << dis[i] << "\n";
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  6
Enter number of edges:  7
Enter the elements:
0 1 5
1 5 -3
1 2 -2
5 3 1
3 2 6
3 4 -2
2 4 3
Enter the source node: 0
0 -> 0: 0
0 -> 1: 5
0 -> 2: 3
0 -> 3: 3
0 -> 4: 1
0 -> 5: 2

Enter number of nodes:  3
Enter number of edges:  3
Enter the elements:
0 1 6
1 2 -12
2 0 -7
Enter the source node: 0
Negative cycle is present
*/