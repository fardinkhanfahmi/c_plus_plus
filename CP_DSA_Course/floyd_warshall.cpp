#include <bits/stdc++.h>
using namespace std;

const int N = 510;
const int INF = 1e9 + 10;

int dist[N][N];

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    // 1. INITIALIZE THE MATRIX FIRST
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j) {
                dist[i][j] = 0;      // Distance to self is 0
            } else {
                dist[i][j] = INF;    // Other nodes are initially unreachable
            }
        }
    }

    // 2. READ EDGES AND POPULATE MATRIX
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int x, y, wt;
        cin >> x >> y >> wt;
        
        // Assuming directed graph. If undirected, also add: dist[y][x] = wt;
        dist[x][y] = wt; 
    }

    cout << "\n--- Starting Floyd-Warshall Algorithm ---" << endl;

    // 3. RUN FLOYD-WARSHALL
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                
                // Prevent integer overflow (INF + INF becomes negative)
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    
                    // Relaxation step
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        int old_dist = dist[i][j];
                        dist[i][j] = dist[i][k] + dist[k][j];
                        
                        cout << "   [Update] Shorter path found from " << i << " to " << j 
                             << " via " << k << ". New dist: " << dist[i][j] 
                             << " (Old: " << (old_dist == INF ? "INF" : to_string(old_dist)) << ")" << endl;
                    }
                }
            }
        }
    }

    // 4. OUTPUT FINAL MATRIX
    cout << "\n--- Final All-Pairs Shortest Paths Matrix ---" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (dist[i][j] == INF) {
                cout << "I "; 
            } else {
                cout << dist[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}