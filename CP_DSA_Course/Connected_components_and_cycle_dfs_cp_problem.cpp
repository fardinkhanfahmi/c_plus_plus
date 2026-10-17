#include <bits/stdc++.h>
using namespace std;
#define    ll      long long int
#define nl "\n"
const int N = 1e5 + 10;
set<ll>s;
set<ll>st;
vector<ll> g[N];
bool vis[N];

void dfs(int vertex) {
    /** Take action on vertex after entering
     *  the vertex
     **/
   // cout << vertex << endl;
    vis[vertex] = true;

    for (int child : g[vertex]) {
       // cout << "par " << vertex << ", child " << child << endl;
        s.insert(vertex);
        s.insert(child);
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
    ll n, m, c=0,j=0,v1, v2;
    cin >> n >> m;
    ll i;
    vector<ll>a(n);
    for(i=0;i<n;i++) a[i]=i+1;
    for ( i = 0; i < m; ++i) {
        cin >> v1 >> v2;
        st.insert(v1);
        st.insert(v2);
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    v1=n-st.size();
    ny:
    while(s.size()+v1<n)
    {
        i=0;
        if(s.size()==0)
        {
            c++;goto my;
        }
        else
        {
            vector<ll>b(n,0);
            j=0;
            for(auto x:s)
            {
                b[j]=x;
                j++;
            }
            for(i=0,j=0;i<n;i++,j++)
            {
                if(a[i]!=b[j]){c++;goto my;}
            }
        }
    }
    cout<<c+v1<<nl;
    return 0;
    my:
    dfs(a[i]);
    goto ny;
}