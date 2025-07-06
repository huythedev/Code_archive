#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start, int n) {
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[start] = 0;
    pq.push({0, start});
    
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        
        if (d > dist[u]) continue;
        
        for (auto& edge : adj[u]) {
            int v = edge.first;
            int cost = edge.second;
            
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push({dist[v], v});
            }
        }
    }
    
    return dist;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        adj.assign(n + 1, vector<pair<int, int>>());
        
        for (int i = 0; i < n - 1; i++) {
            int x, y;
            cin >> x >> y;
            
            adj[x].push_back({y, 0});
            adj[y].push_back({x, 1});
        }
        
        // Precompute distances from all nodes
        vector<vector<int>> distFrom(n + 1);
        for (int i = 1; i <= n; i++) {
            distFrom[i] = dijkstra(i, n);
        }
        
        int minReversals = INT_MAX;
        
        // Try all possible pairs (a, b) as key intersections
        for (int a = 1; a <= n; a++) {
            for (int b = a; b <= n; b++) {
                int totalReversals = 0;
                bool valid = true;
                
                for (int start = 1; start <= n; start++) {
                    if (start == a || start == b) continue;
                    
                    int distToA = distFrom[start][a];
                    int distToB = distFrom[start][b];
                    
                    if (distToA == INT_MAX && distToB == INT_MAX) {
                        valid = false;
                        break;
                    }
                    
                    if (distToA == INT_MAX) {
                        totalReversals += distToB;
                    } else if (distToB == INT_MAX) {
                        totalReversals += distToA;
                    } else {
                        totalReversals += min(distToA, distToB);
                    }
                }
                
                if (valid) {
                    minReversals = min(minReversals, totalReversals);
                }
            }
        }
        
        cout << minReversals << "\n";
    }
    
    return 0;
}
