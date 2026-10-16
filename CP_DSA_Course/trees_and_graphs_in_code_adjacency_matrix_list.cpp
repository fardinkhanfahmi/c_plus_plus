#include <bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int main()
{
    int n,m,i;
    cin>>n>>m;
    vector <pair<int,int>>graph[N];
    for( i=0;i<m;i++)
    {
        int v1,v2,wt;
        cin>>v1>>v2>>wt;
        graph[v1].push_back({v2,wt});
        graph[v2].push_back({v1,wt});
    }
    for (int i = 1; i <= N; i++)
{
    if (graph[i].empty())
        continue;
        
    cout << "Node " << i << ": ";

    for (auto edge : graph[i])
    {
        cout << "(" << edge.first << ", " << edge.second << ") ";
    }

    cout << endl;
}
    return 0;
}