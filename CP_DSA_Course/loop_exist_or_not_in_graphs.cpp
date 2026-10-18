#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int c=0;
vector<int> g[N],g2[N];
bool vis[N];

void dfs(int vertex) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    cout << vertex << endl;
    vis[vertex] = true;
    int d=1;
    for (int child : g[vertex]) {
        cout << "par " << vertex << ", child " << child << endl;
        if (vis[child] && d==1) {continue;}
        else if(vis[child] && d!=1) c++;
        
        /** Take action on child before
         *  entering the child node
         **/
        dfs(child);
        d++;
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
    cout<<c<<endl;
    return 0;
}