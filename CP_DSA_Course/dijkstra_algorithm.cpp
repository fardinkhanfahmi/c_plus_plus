#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
const int INF = 1e9 + 10;

// Graph representation: g[node] = vector of {neighbor, weight}
vector<pair<int, int>> g[N];

void dijkstra(int source) {
    // vis array to keep track of processed nodes
    vector<int> vis(N, 0); 
    // dist array initialized to infinity
    vector<int> dist(N, INF); 
    
    // Set stores pairs of {distance, node}. 
    // It automatically keeps the smallest distance at the beginning.
    set<pair<int, int>> st; 
    
    // Initialize source
    st.insert({0, source});
    dist[source] = 0;
    
    cout << "--- Starting Dijkstra from source: " << source << " ---" << endl;

    while (st.size() > 0) {
        // Get the node with the smallest distance
        auto node = *st.begin();
        int v = node.second;
        int d = node.first;
        
        // CRITICAL: Remove the node from the set (visible in the final screenshot)
        st.erase(st.begin()); 
        
        // If we have already processed this node, skip it
        if (vis[v]) continue;
        vis[v] = 1; // Mark as visited
        
        cout << "\n>> Processing Node: " << v << " (Current shortest distance from source: " << d << ")" << endl;

        // Iterate through all children (neighbors)
        for (auto child : g[v]) {
            int child_v = child.first;
            int wt = child.second;
            
            // Relaxation step: Check if a shorter path is found
            if (dist[v] + wt < dist[child_v]) {
                int old_dist = dist[child_v];
                dist[child_v] = dist[v] + wt;
                
                // Insert the new updated distance into the set
                st.insert({dist[child_v], child_v});
                
                cout << "   [Relaxation] Found shorter path to " << child_v 
                     << " via " << v << ". Updated distance: " << dist[child_v] 
                     << " (Previous: " << (old_dist == INF ? "INF" : to_string(old_dist)) << ")" << endl;
            }
        }
    }
    
    cout << "\n--- Final Shortest Distances from Source " << source << " ---" << endl;
    for (int i = 1; i <= 5; ++i) { // Printing for first 5 nodes as an example
        if (dist[i] == INF) cout << "Node " << i << ": Unreachable" << endl;
        else cout << "Node " << i << ": " << dist[i] << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;
    
    cout << "Enter edges (u v weight):" << endl;
    for (int i = 0; i < m; ++i) {
        int x, y, wt;
        cin >> x >> y >> wt;
        // Assuming a directed graph based on your screenshot.
        // If it's undirected, add: g[y].push_back({x, wt});
        g[x].push_back({y, wt});
    }
    
    // Example: Start Dijkstra from node 1
    dijkstra(1);

    return 0;
}