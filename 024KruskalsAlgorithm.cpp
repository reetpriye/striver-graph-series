#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N) + O(N) + O(N) + O(3*M) ~= O(N)
// For disjoint set
// O(N) -> For rank array
// O(N) -> For par array
// O(N) -> Auxiliary space for stack
// For algo part
// O(3*M) -> To store edges with weight

// Time complexity: O(MlogM) + O(M*O(4alpha)) ~= O(MlogM)
// O(MlogM) -> To sort the edges
// O(M*O(4alpha)) -> Traversing all edges and checking if they belong
// to same component or not using disjoint set which takes O(4alpha)
// It will be logarithmic if we are not using path compression

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

bool comp(Node a, Node b) {
    return a.wt < b.wt;
}

int findPar(int node, vector<int> &par) {
    if(par[node]==node) return node;

    return par[node] = findPar(par[node], par);
}

void unionn(int u, int v, vector<int> &par, vector<int> &rank) {
    u = findPar(u, par);
    v = findPar(v, par);

    if(rank[u] > rank[v])
        par[v] = u;
    else if(rank[u] < rank[v])
        par[u] = v;
    else {
        par[v] = u;
        rank[u]++;
    }
}

int main() {    
    int n; // Number of nodes
    int m; // Number of edges
    cout << "Enter number of nodes:\t";
    cin >> n;
    cout << "Enter number of edges:\t";
    cin >> m;
    cout << "Enter the edges\n";
    vector<Node> edges;
    for(int i=0; i<m; i++) {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(Node(u, v, wt));
    }
    sort(edges.begin(), edges.end(), comp);
    
    vector<int> par(n);
    vector<int> rank(n);
    vector<pair<int, int>> mst;
    for(int i=0; i<n; i++)   
        par[i] = i;
    int cost = 0;
    for(auto it: edges) {
        if(findPar(it.u, par)!=findPar(it.v, par)) {
            cost += it.wt;
            unionn(it.u, it.v, par, rank);
            mst.push_back({it.u, it.v});
        }
    }
    cout << "\n";
    cout << "Cost: " << cost << "\n";
    for(auto it: mst) {
        cout << it.first << " - " << it.second << "\n";
    }
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  6
Enter number of edges:  9
Enter the edges
4 3 9
3 2 5
2 5 8
4 0 4
3 0 1
0 1 2
3 1 3
2 1 3
1 5 7

Cost: 17
3 - 0
0 - 1
2 - 1
4 - 0
1 - 5
*/