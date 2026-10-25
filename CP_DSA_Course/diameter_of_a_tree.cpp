#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

vector<int> g[N],forward_length(N,0),backward_length(N,0);
bool vis[N];
int c,d1=0,d2=0;
void dfs(int vertex,int c) {
    /** Take action on vertex after entering
     *  the vertex
     **/
    cout << vertex << endl;
    vis[vertex] = true;
    for (int child : g[vertex]) {
        cout << "par " << vertex << ", child " << child << endl;
        backward_length[vertex]=c;
        if (vis[child]) continue;
        /** Take action on child before
         *  entering the child node
         **/
        dfs(child,c+1);
        if(forward_length[vertex]<=forward_length[child]+1){
            forward_length[vertex]=forward_length[child]+1;
        }
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
    dfs(1,0);
    for(int i=1;i<=n;i++)
    {
        cout<<"forward length of "<<i<<" is "<<forward_length[i]<<endl;
        cout<<"backward length of "<<i<<" is "<<backward_length[i]<<endl;
        if(d1<backward_length[i]){
            d2=max(d1,d2);
            d1=backward_length[i];
            cout<<"d1 is "<<d1<<endl;
        }
        else if(d2<backward_length[i]){
            d2=backward_length[i];
            cout<<"d2 is "<<d2<<endl;
        }
    }
    cout<<"Diameter of the tree is "<<d1+d2<<endl;
    return 0;
}