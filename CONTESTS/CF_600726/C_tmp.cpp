#include <bits/stdc++.h>
using namespace std;

// Fenwick Tree for dynamic updates and range queries
struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) : n(n), bit(n + 1, 0) {}

    // Add value at index
    void add(int idx, int val) {
        for (++idx; idx <= n; idx += idx & -idx) {
            bit[idx] += val;
        }
    }

    // Sum from index 0 to idx
    int prefix_sum(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
        }
        return ret;
    }

    // Sum from index l to r (inclusive)
    int sum(int l, int r) {
        return prefix_sum(r) - prefix_sum(l - 1);
    }
};

void solve(int case_num) {
    int n, p;
    cin >> n >> p;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // Collect all unique values from a[i] and b[i] as potential x
    vector<int> all_values;
    for (int i = 0; i < n; i++) {
        all_values.push_back(a[i]);
        all_values.push_back(b[i]);
    }
    sort(all_values.begin(), all_values.end());
    all_values.erase(unique(all_values.begin(), all_values.end()), all_values.end());
    int k = all_values.size();

    // Compress values to ranks for Fenwick Tree
    vector<int> rank_a(n), rank_b(n);
    for (int i = 0; i < n; i++) {
        rank_a[i] = lower_bound(all_values.begin(), all_values.end(), a[i]) - all_values.begin() + 1;
        rank_b[i] = lower_bound(all_values.begin(), all_values.end(), b[i]) - all_values.begin() + 1;
    }

    // Events map: when to switch from b[i] to a[i]
    map<int, vector<int>> events;
    for (int i = 0; i < n; i++) {
        events[a[i]].push_back(i);
    }

    // Initialize Fenwick Tree with all s[i] = b[i]
    FenwickTree ft(k);
    for (int i = 0; i < n; i++) {
        ft.add(rank_b[i], 1);
    }

    int max_passing = 0;
    // Process each possible x in ascending order
    for (int x : all_values) {
        // Update scores: switch from b[i] to a[i] when a[i] <= x
        if (events.count(x)) {
            for (int i : events[x]) {
                ft.add(rank_b[i], -1); // Remove b[i]
                ft.add(rank_a[i], 1);  // Add a[i]
            }
        }

        // Check if x is achievable (at least one s[i] = x)
        int rank_x = lower_bound(all_values.begin(), all_values.end(), x) - all_values.begin() + 1;
        if (ft.sum(rank_x, rank_x) > 0) {
            // Compute threshold: ceil(x * p / 100)
            long long temp = (long long)x * p;
            int threshold = (temp + 99) / 100; // Ceiling division
            int r = lower_bound(all_values.begin(), all_values.end(), threshold) - all_values.begin();
            // Count students with s[i] >= threshold
            int passing = (r < k) ? ft.sum(r + 1, k) : 0;
            max_passing = max(max_passing, passing);
        }
    }

    cout << "Case #" << case_num << ": " << max_passing << "\n";
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve(t);
    }
    return 0;
}