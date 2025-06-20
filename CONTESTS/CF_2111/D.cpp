// Author: huythedev
// Problem Link: https://codeforces.com/contest/2111/problem/D
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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ll> a(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }

    map<ll, vector<ll>> mp;
    for (int i = 0; i < m; i++) {
        ll floor = a[i] / 100;
        mp[floor].push_back(a[i]);
    }
    set<ll> st;
    for (pair<ll, vector<ll>> i : mp) {
        if (!i.second.empty()) {
            st.insert(i.first);
        }
    }
    
    vector<vector<ll>> schedules(n, vector<ll>(6));
    int tmp = 0;
    while (tmp < n && !st.empty()) {
        ll f_left = *st.begin();
        ll f_right = *st.rbegin();
        if (f_left < f_right) {
            ll c1 = mp[f_left][0];
            mp[f_left].erase(mp[f_left].begin());
            ll c2 = mp[f_right][0];
            mp[f_right].erase(mp[f_right].begin());

            int tmp2 = min(2, n - tmp);
            for (int i = 0; i < tmp2; i++) {
                int group = tmp + i;
                for (int j = 0; j < 6; j++) {
                    if ((j % 2 == 0 && i == 0) || (j % 2 == 1 && i == 1)) {
                        schedules[group][j] = c1;
                    } else {
                        schedules[group][j] = c2;
                    }
                }
            }

            tmp += tmp2;

            if (mp[f_left].empty()) {
                st.erase(f_left);
            }
            if (mp[f_right].empty()) {
                st.erase(f_right);
            }
        } else {
            if (mp[f_left].size() >= 2) {
                ll c1 = mp[f_left][0];
                ll c2 = mp[f_left][1];
                mp[f_left].erase(mp[f_left].begin(), mp[f_left].begin() + 2);

                int tmp2 = min(2, n - tmp);
                for (int i = 0; i < tmp2; i++) {
                    int group = tmp + i;
                    for (int j = 0; j < 6; j++) {
                        if ((j % 2 == 0 && i == 0) || (j % 2 == 1 && i == 1)) {
                            schedules[group][j] = c1;
                        } else {
                            schedules[group][j] = c2;
                        }
                    }
                }

                tmp += tmp2;
            } else {
                ll c1 = mp[f_left][0];
                mp[f_left].erase(mp[f_left].begin());

                int tmp2 = tmp;
                for (int i = 0; i < 6; i++) {
                    schedules[tmp2][i] = c1;
                }

                tmp += 1;
            }

            if (mp[f_left].empty()) {
                st.erase(f_left);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cout << schedules[i][j] << " ";
        }
        cout << ln;
    }
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