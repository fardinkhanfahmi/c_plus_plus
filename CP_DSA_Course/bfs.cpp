#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
vector<int> g[N];

int vis[N];
int level[N];

void bfs(int source) {
    queue<int> q;
    q.push(source);
    vis[source] = 1;

    while (!q.empty()) {
        int cur_v = q.front();
        q.pop();
        
        // Optional: Print the current node being visited (from Image 3)
        cout << cur_v << " "; 
        
        for (int child : g[cur_v]) {
            if (!vis[child]) {
                q.push(child);
                vis[child] = 1;
                // Calculate level based on parent's level + 1
                level[child] = level[cur_v] + 1;
            }
        }
    }
    cout << endl; // Print newline after BFS traversal (from Image 3)
}

int main() {
    int n;
    cin >> n;

    // Reading edges for a tree with n nodes (n-1 edges)
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    bfs(1);

    // Printing the level of each node from 1 to n
    for (int i = 1; i <= n; ++i) {
        cout << i << ": " << level[i] << endl;
    }

    return 0;
}