#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
int depth[N], height[N];

void dfs(int vertex, int par=0) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    cout << vertex << endl;

    for (int child : g[vertex]) {
        cout << "par " << vertex << ", child " << child << endl;
        /** Take action on child before
         *  entering the child node
         **/
        if (child == par) continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
        /** Take action on child
         *  after exiting child node
         **/
    }
    /** Take action on vertex before
     *  exiting the vertex
     **/
}

int main() {
    int n;
    cin >> n;
    
    // CORRECTED: Loop runs 'm' times based on input, not 9
    for (int i = 0; i < n - 1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    
    // Example: Start DFS from node 1
    // (This line wasn't visible in the screenshots, but is needed to run the code)
    dfs(1);
    for(int i=1;i<=n;i++)
    {
        cout<<"Depth of "<<i<<" is "<<depth[i]<<" and Height is "<<height[i]<<endl;
    }
    return 0;
}