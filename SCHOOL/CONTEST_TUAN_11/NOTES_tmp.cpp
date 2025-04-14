#include <bits/stdc++.h>
using namespace std;

int main() {
    // Optimize input/output
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // Read number of teammates
    int n;
    cin >> n;

    // Read transfer cost matrix C (0-based indexing for friends 1 to n)
    vector<vector<int>> C(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> C[i][j];
        }
    }

    // Read return costs D (0-based indexing for friends 1 to n)
    vector<int> D(n);
    for (int i = 0; i < n; i++) {
        cin >> D[i];
    }

    // Initialize MST structures: nodes 0 (Linh) to n (teammates)
    vector<bool> in_tree(n + 1, false);      // Tracks nodes in MST
    vector<long long> dist(n + 1, LLONG_MAX); // Minimum cost to connect to MST
    in_tree[0] = true;                       // Start with Linh in the tree
    for (int k = 1; k <= n; k++) {
        dist[k] = D[k - 1];                  // Initial cost to return directly to Linh
    }

    long long total_cost = 0;
    // Add n teammates to the MST
    for (int i = 0; i < n; i++) {
        // Find unadded teammate u with minimum distance to the tree
        int u = -1;
        long long min_dist = LLONG_MAX;
        for (int k = 1; k <= n; k++) {
            if (!in_tree[k] && dist[k] < min_dist) {
                min_dist = dist[k];
                u = k;
            }
        }

        // If no node found, all are connected (shouldn’t happen with valid input)
        if (u == -1) break;

        // Add u to the tree and update total cost
        in_tree[u] = true;
        total_cost += dist[u];

        // Update distances for remaining teammates
        for (int v = 1; v <= n; v++) {
            if (!in_tree[v] && C[u - 1][v - 1] < dist[v]) {
                dist[v] = C[u - 1][v - 1]; // Cheaper to transfer from u to v
            }
        }
    }

    // Output the minimum total cost
    cout << total_cost << endl;

    return 0;
}