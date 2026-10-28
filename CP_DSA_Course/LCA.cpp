
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int parent[N];
int depth[N];

void dfs(int vertex, int par) {
    parent[vertex] = par;

    for (int child : g[vertex]) {
        if (child == par) continue;

        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
    }
}

int lca(int a, int b) {
    // Bring both vertices to the same depth
    while (depth[a] > depth[b]) {
        a = parent[a];
    }

    while (depth[b] > depth[a]) {
        b = parent[b];
    }

    // Move both vertices upward until they meet
    while (a != b) {
        a = parent[a];
        b = parent[b];
    }

    return a;
}

int main() {
    int n;
    cin >> n;

    // Input n-1 edges of the tree
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, 0);  // Root the tree at vertex 1

    int a, b;
    cin >> a >> b;

    cout << lca(a, b) << '\n';

    return 0;
}