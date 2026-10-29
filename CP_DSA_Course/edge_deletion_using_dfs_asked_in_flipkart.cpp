#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int,pair<int,int>> g[N];
bool vis[N];

void sum_dfs(int vertex) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    cout << vertex << endl;
    //vis[vertex] = true;

    for (const auto &edge : g[vertex]) {
        int child = edge.first; 
        cout << "par " << vertex << ", child " << child << endl;
        //if (vis[child]) continue;
        
        /** Take action on child before
         *  entering the child node
         **/
       sum_dfs(child.first);
         g[vertex].insert(child.first,child.second+child.first);
        /** Take action on child
         *  after exiting child node
         **/
    }
    g[vertex].insert(vertex,);
    /** Take action on vertex before
     *  exiting the vertex
     **/
}

int main() {
    int n, m;
    cin >> n;
    
    // CORRECTED: Loop runs 'm' times based on input, not 9
    for (int i = 0; i < n-1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2,0);
        //g[v2].push_back(v1);
    }
    
    // Example: Start DFS from node 1
    // (This line wasn't visible in the screenshots, but is needed to run the code)
    sum_dfs(1);

    return 0;
}