// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/gym/592085/problem/E
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

struct State {
    int h1, t1, h2, t2, h3, t3;
    bool operator<(const State& other) const {
        return tie(h1, t1, h2, t2, h3, t3) < tie(other.h1, other.t1, other.h2, other.t2, other.h3, other.t3);
    }
};

bool dominates(const State& a, const State& b) {
    return a.h1 <= b.h1 && a.t1 <= b.t1 && a.h2 <= b.h2 && a.t2 <= b.t2 &&
           a.h3 <= b.h3 && a.t3 <= b.t3 &&
           (a.h1 < b.h1 || a.t1 < b.t1 || a.h2 < b.h2 || a.t2 < b.t2 || a.h3 < b.h3 || a.t3 < b.t3);
}

vector<State> merge_states(vector<State>& states) {
    if (states.empty()) return {};
    sort(states.begin(), states.end());
    vector<State> pruned;
    for (const State& s : states) {
        bool dominated = false;
        for (int i = (int)pruned.size() - 1; i >= max(0, (int)pruned.size() - 5); --i) {
            if (dominates(pruned[i], s)) {
                dominated = true;
                break;
            }
        }
        if (!dominated) {
            while (!pruned.empty() && dominates(s, pruned.back())) {
                pruned.pop_back();
            }
            pruned.push_back(s);
        }
    }
    return pruned;
}

int main() {
    fastio();
    docfile();
    
    int n;
    cin >> n;
    vector<pair<int, int>> books(n);
    for (int i = 0; i < n; ++i) {
        cin >> books[i].first >> books[i].second; 
    }

    sort(books.begin(), books.end(), greater<>());

    vector<vector<State>> dp(8);
    dp[0].push_back({0, 0, 0, 0, 0, 0});

    int total_t = 0;
    for (auto [h, t] : books) total_t += t;
    int max_t_bound = total_t; 
    for (const auto& [h, t] : books) {
        vector<vector<State>> new_dp(8);
        for (int mask = 0; mask < 8; ++mask) {
            for (const State& s : dp[mask]) {
                for (int shelf = 0; shelf < 3; ++shelf) {
                    State next = s;
                    int new_mask = mask | (1 << shelf);
                    if (shelf == 0) {
                        next.h1 = max(next.h1, h);
                        next.t1 += t;
                        if (next.t1 > max_t_bound) continue;
                    } else if (shelf == 1) {
                        next.h2 = max(next.h2, h);
                        next.t2 += t;
                        if (next.t2 > max_t_bound) continue;
                    } else {
                        next.h3 = max(next.h3, h);
                        next.t3 += t;
                        if (next.t3 > max_t_bound) continue;
                    }
                    new_dp[new_mask].push_back(next);
                }
            }
        }
        for (int m = 0; m < 8; ++m) {
            dp[m] = merge_states(new_dp[m]);
            if (dp[m].size() > 1000) { 
                dp[m].resize(1000);
            }
        }
    }

    int res = INT_MAX;
    for (const State& s : dp[7]) {
        int sumH = s.h1 + s.h2 + s.h3;
        int maxT = max({s.t1, s.t2, s.t3});
        res = min(res, sumH * maxT);
    }

    cout << res << ln;

    time();
    return 0;
}