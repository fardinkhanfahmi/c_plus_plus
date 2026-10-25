#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int c,d;
vector<int> g[N];
vector<int> sum(N, 0), odd_even_count(N, 0);
bool vis[N];

void dfs(int vertex) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    c=0;
    // cout << vertex << endl;
    vis[vertex] = true;

    for (int child : g[vertex]) {
       // cout << "par " << vertex << ", child " << child << endl;
        /** Take action on child before
         *  entering the child node
         **/
        if (vis[child]) continue;
        dfs(child);
        odd_even_count[vertex] += odd_even_count[child];
        c++;
        sum[vertex]+=sum[child];
        /** Take action on child
         *  after exiting child node
         **/
    }
    if(c==0) sum[vertex]=vertex;
    else sum[vertex]+=vertex;
    if(c==0) {
        if(vertex%2==0) odd_even_count[vertex]=1;
        else odd_even_count[vertex]=0;
    }
    else {
        if(vertex%2==0) odd_even_count[vertex]+=1;
    }
    /** Take action on vertex before
     *  exiting the vertex
     **/
}

int main() {
    int n, m;
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
        cout<<"sum of subtree of "<<i<<" is "<<sum[i]<<endl;
        cout<<"count of odd numbers in subtree of "<<i<<" is "<<odd_even_count[i]<<endl;
    }
    return 0;
}