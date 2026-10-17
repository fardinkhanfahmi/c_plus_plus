#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
set<int>s;
vector<int> g[N];
bool vis[N];

void dfs(int vertex) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    cout << vertex << endl;
    vis[vertex] = true;
    for (int child : g[vertex]) {
        cout << "par " << vertex << ", child " << child << endl;
        if (vis[child]) continue;
        
        /** Take action on child before
         *  entering the child node
         **/
        dfs(child);
        /** Take action on child
         *  after exiting child node
         **/
    }
    /** Take action on vertex before
     *  exiting the vertex
     **/
}

int main() {
    int n, m;
    cin >> n >> m;
    
    // CORRECTED: Loop runs 'm' times based on input, not 9
    for (int i = 0; i < m; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    // Example: Start DFS from node 1
    // (This line wasn't visible in the screenshots, but is needed to run the code)
    dfs(1);

    return 0;
}