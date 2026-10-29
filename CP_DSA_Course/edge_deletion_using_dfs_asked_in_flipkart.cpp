#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N];
vector<int> sum(N, 0);
int b=0,c;
bool vis[N];
void edge_deletion(int vertex, int a) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    cout << vertex << endl;
    //vis[vertex] = true;

    for (int child : g[vertex]) {
        cout << "par " << vertex << ", child " << child << endl;
        //if (vis[child]) continue;
        
        /** Take action on child before
         *  entering the child node
         **/
        edge_deletion(child, a);
        /** Take action on child
         *  after exiting child node
         **/
    }
    if((a-sum[vertex])*sum[vertex]>b) {
        b=(a-sum[vertex])*sum[vertex];
        c=vertex;
    }
}
void sum_dfs(int vertex) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    cout << vertex << endl;
    //vis[vertex] = true;

    for (int child : g[vertex]) {
        cout << "par " << vertex << ", child " << child << endl;
        //if (vis[child]) continue;
        
        /** Take action on child before
         *  entering the child node
         **/
        sum_dfs(child);
        sum[vertex] += sum[child];
        /** Take action on child
         *  after exiting child node
         **/
    }
    sum[vertex] += vertex;
    cout<< "sum of vertex " << vertex << " is " << sum[vertex] << endl;
    /** Take action on vertex before
     *  exiting the vertex
     **/
}

int main() {
    int n, v3;
    cin >> n;
    
    // CORRECTED: Loop runs 'm' times based on input, not 9
    for (int i = 0; i < n-1; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g[v1].push_back(v2);
        if(i==0) v3=v1;
        //g[v2].push_back(v1);
    }
    
    // Example: Start DFS from node 1
    // (This line wasn't visible in the screenshots, but is needed to run the code)
    sum_dfs(v3);
    int a=sum[v3];
    edge_deletion(v3,a);
    cout << "Vertex with maximum edge deletion value: " << c <<", Value: " << b << endl;
    return 0;
}