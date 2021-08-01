#include <bits/stdc++.h>

using namespace std;

// Space complexity: O(N) + O(N) + O(N) ~= O(N)
// O(N) -> For rank array
// O(N) -> For par array
// O(N) -> Auxiliary space for stack

// Time complexity: O(4alpha)
// It will be logarithmic if we are not using path compression

int findPar(int node, vector<int> &par) {
    if(par[node]==node) return node;
    // Path compression[storing the returned value]
    return par[node] = findPar(par[node], par);
}

void unionn(int u, int v, vector<int> &rank, vector<int> &par) {
    u = findPar(u, par);
    v = findPar(v, par);

    if(rank[u]>rank[v])
        par[v] = u;
    else if(rank[u]<rank[v])
        par[u] = v;
    else {
        par[v] = u;
        rank[u]++;
    }
}

int main() {
    int m;
    int n;
    cout << "Enter number of nodes:\t";
    cin >> n;
    cout << "How many unions you are going to perform? :\t ";
    cin >> m;
    cout << "Enter the elements:\n";
    
    vector<int> par(n);
    vector<int> rank(n);

    for(int i=0; i<n; i++)
        par[i] = i;

    while(m--) {
        int u, v;
        cin >> u >> v;
        unionn(u, v, rank, par);
    }

    for(int i=0; i<7; i++) {
        cout << "Parent of " << i << " is: " << par[i] << "\n";
    }

    int a, b;
    cout << "Enter nodes to check if they belong to same component or not: ";
    cin >> a >> b;
    if(findPar(a, par)==findPar(b, par))
        cout << a << " and " << b << " belongs to the same component\n";
    else 
        cout << a << " and " << b << " belongs to the different component\n";
}

/*
WARNING: Output may vary according to
architecture type or input.
Output of the program : 
Enter number of nodes:  7
How many unions you are going to perform? :   6
Enter the elements:
0 1
1 2
3 4
5 6
4 5
2 6
Parent of 0 is: 3
Parent of 1 is: 0
Parent of 2 is: 0
Parent of 3 is: 3
Parent of 4 is: 3
Parent of 5 is: 3
Parent of 6 is: 3
Enter nodes to check if they belong to same component or not: 2 3
2 and 3 belong to the same component
*/