#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }

    if (n == 0) {
        cout << 0 << endl;
        return;
    }

    vector<long long> final_h = h;

    // Left-to-right pass
    for (int i = 1; i < n; ++i) {
        final_h[i] = max(final_h[i], final_h[i - 1] - 1);
    }

    // Right-to-left pass
    for (int i = n - 2; i >= 0; --i) {
        final_h[i] = max(final_h[i], final_h[i + 1] - 1);
    }

    long long total_cost = 0;
    for (int i = 0; i < n; ++i) {
        total_cost += final_h[i] - h[i];
    }

    cout << total_cost << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
