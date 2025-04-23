// Author: huythedev (https://huythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc044c10f

#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc044c10f"
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

int main() {
    fastio();
    docfile();

    ll N, K;
    cin >> N >> K;
    vector<tuple<ll, ll, ll, ll>> operations(K);
    for (ll i = 0; i < K; i++) {
        ll r1, r2, c1, c2;
        cin >> r1 >> r2 >> c1 >> c2;
        operations[i] = {r1, r2, c1, c2};
    }
    ll A, B;
    cin >> A >> B;

    vector<ll> row_events;
    for (const auto& op : operations) {
        ll r1, r2;
        tie(r1, r2, ignore, ignore) = op;
        row_events.push_back(r1);
        row_events.push_back(r2 + 1); 
    }
    sort(row_events.begin(), row_events.end());
    row_events.erase(unique(row_events.begin(), row_events.end()), row_events.end());

    map<ll, vector<pair<ll, ll>>> op_start, op_end;
    for (const auto& op : operations) {
        ll r1, r2, c1, c2;
        tie(r1, r2, c1, c2) = op;
        op_start[r1].emplace_back(c1, c2);
        op_end[r2 + 1].emplace_back(c1, c2); 
    }

    set<pair<ll, ll>> active_ops; 
    ll P = 0, E = 0, prev_row = 1;

    for (ll curr_row : row_events) {
        if (curr_row > N + 1) break; 
        ll row_start = prev_row;
        ll row_end = curr_row - 1;
        if (row_start > N) break;
        if (op_start.count(curr_row)) {
            for (const auto& op : op_start[curr_row]) {
                active_ops.insert(op);
            }
        }
        if (op_end.count(curr_row)) {
            for (const auto& op : op_end[curr_row]) {
                active_ops.erase(op);
            }
        }

        if (!active_ops.empty()) {
            vector<pair<ll, int>> col_events;
            for (const auto& op : active_ops) {
                col_events.emplace_back(op.first, 1);        
                col_events.emplace_back(op.second + 1, -1); 
            }
            sort(col_events.begin(), col_events.end());

            ll active_count = 0, col_prev = 1;
            for (const auto& event : col_events) {
                ll col = event.first;
                int delta = event.second;
                if (col > N + 1) break;

                if (active_count > 0) {
                    ll col_len = min(N + 1, col) - col_prev;
                    if (col_len > 0) {
                        ll row_len = min(N, row_end) - row_start + 1;
                        if (row_len > 0) {
                            P += col_len * row_len; 
                            if (active_count % 2 == 0) {
                                E += col_len * row_len;
                            }
                        }
                    }
                }
                active_count += delta;
                col_prev = col;
            }
        }
        prev_row = curr_row;
    }

    ll result = P * A + E * B;
    cout << result << "\n";

    time();
    return 0;
}