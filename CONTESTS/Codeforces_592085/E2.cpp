// Author: huythedev (https://huythedev.com)
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

map<int, vector<State>> generate_states(const vector<pair<int, int>>& books, int start, int end) {
    map<int, vector<State>> dp;
    dp[0].push_back({0, 0, 0, 0, 0, 0});
    
    for (int i = start; i < end; ++i) {
        int h = books[i].first, t = books[i].second;
        map<int, vector<State>> new_dp;
        for (const auto& [mask, states] : dp) {
            for (const State& s : states) {
                for (int shelf = 0; shelf < 3; ++shelf) {
                    State next = s;
                    int new_mask = mask | (1 << shelf);
                    if (shelf == 0) {
                        next.h1 = max(next.h1, h);
                        next.t1 += t;
                    } else if (shelf == 1) {
                        next.h2 = max(next.h2, h);
                        next.t2 += t;
                    } else {
                        next.h3 = max(next.h3, h);
                        next.t3 += t;
                    }
                    new_dp[new_mask].push_back(next);
                }
            }
        }
        for (auto& [m, states] : new_dp) {
            set<State> pruned;
            for (const State& s : states) {
                bool dominated = false;
                for (const State& p : pruned) {
                    if (dominates(p, s)) {
                        dominated = true;
                        break;
                    }
                }
                if (!dominated) {
                    auto it = pruned.begin();
                    while (it != pruned.end() && !dominates(s, *it)) ++it;
                    if (it == pruned.end() || !dominates(s, *it)) pruned.insert(s);
                }
            }
            states.assign(pruned.begin(), pruned.end());
        }
        dp = move(new_dp);
    }
    return dp;
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
    
    int mid = n / 2;
    auto first_half = generate_states(books, 0, mid);
    auto second_half = generate_states(books, mid, n);
    
    int res = INT_MAX;
    for (const auto& [mask1, states1] : first_half) {
        for (const auto& [mask2, states2] : second_half) {
            if ((mask1 | mask2) != 7) continue; 
            for (const State& s1 : states1) {
                for (const State& s2 : states2) {
                    int h1 = max(s1.h1, s2.h1);
                    int h2 = max(s1.h2, s2.h2);
                    int h3 = max(s1.h3, s2.h3);
                    int t1 = s1.t1 + s2.t1;
                    int t2 = s1.t2 + s2.t2;
                    int t3 = s1.t3 + s2.t3;
                    int cost = (h1 + h2 + h3) * max({t1, t2, t3});
                    res = min(res, cost);
                }
            }
        }
    }

    cout << res << ln;

    time();
    return 0;
}