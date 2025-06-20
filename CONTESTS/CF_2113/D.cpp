// Author: huythedev
// Problem Link: https://codeforces.com/contest/2113/problem/D
#include <bits/stdc++.h>
using namespace std;

#define NAME "D"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

int compute(const vector<int>& a, const vector<int>& b, int n, vector<pair<int, int>>& losses) {
    int player_idx = 0, dealer_idx = 0, score = 0;
    losses.clear();
    for (int i = 0; i < n; ++i) {
        if (a[player_idx] > b[dealer_idx]) {
            score++;
            player_idx++;
        } else {
            losses.push_back({player_idx, dealer_idx});
            dealer_idx++;
        }
    }
    return score;
}

int simulate_with_swap(const vector<int>& a, const vector<int>& b, int n, int swap_i, int swap_j) {
    vector<int> a_swapped = a;
    swap(a_swapped[swap_i], a_swapped[swap_j]);
    int player_idx = 0, dealer_idx = 0, score = 0;
    for (int k = 0; k < n; ++k) {
        if (a_swapped[player_idx] > b[dealer_idx]) {
            score++;
            player_idx++;
        } else {
            dealer_idx++;
        }
    }
    return score;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    // Compute suffix maximum
    vector<int> suffix_max(n);
    suffix_max[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        suffix_max[i] = max(a[i], suffix_max[i + 1]);
    }

    // Compute initial score and collect losses
    vector<pair<int, int>> losses;
    int max_score = compute(a, b, n, losses);

    // Group losses by player index and track max dealer card
    map<int, int> loss_map; // {player_idx, max_dealer_card}
    for (auto [player_idx, dealer_idx] : losses) {
        loss_map[player_idx] = max(loss_map[player_idx], b[dealer_idx]);
    }

    // Limit to first 50 distinct losing player indices
    vector<int> distinct_losses;
    for (auto& [player_idx, _] : loss_map) {
        distinct_losses.push_back(player_idx);
        if (distinct_losses.size() == 50) break;
    }

    // For each selected losing index, find best swap and simulate
    for (int player_idx : distinct_losses) {
        int max_dealer_card = loss_map[player_idx];
        int left = player_idx + 1, right = n - 1, best_swap = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (suffix_max[mid] > max_dealer_card) {
                best_swap = mid;
                left = mid + 1; // Look for rightmost candidate
            } else {
                right = mid - 1;
            }
        }
        if (best_swap != -1) {
            int score = simulate_with_swap(a, b, n, player_idx, best_swap);
            max_score = max(max_score, score);
        }
    }

    cout << max_score << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}