// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "OLP"
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

const int MAXN = 1e3 + 5;

signed main() {
    fastio();
    docfile();

    int teams, students_per_team, queries;
    cin >> teams >> students_per_team >> queries;

    vector<vector<ll>> a(teams, vector<ll>(students_per_team));
    for (int i = 0; i < teams; ++i) {
        for (int j = 0; j < students_per_team; ++j) {  
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> p(teams, vector<ll>(students_per_team + 1, 0));
    for (int i = 0; i < teams; ++i) {
        for (int j = 1; j <= students_per_team; ++j) {
            p[i][j] = p[i][j - 1] + a[i][j - 1];
        }
    }

    while (queries--) {
        ll t;
        cin >> t;

        ll best_k = -1;      
        ll best_num = -1;   
        ll best_den = -1;     
        int best_index = -1; 

        for (int i = 0; i < teams; ++i) {
            ll left = 0, right = 1e18;
            while (left < right) {
                ll mid = left + (right - left + 1) / 2;
                ll q = mid / students_per_team;
                ll r = mid % students_per_team;
                __int128 sum_mid = (__int128)q * p[i][students_per_team] + p[i][r];
                if (sum_mid <= t) {
                    left = mid;
                } else {
                    right = mid - 1;
                }
            }
            ll k = left;
            ll q = k / students_per_team;
            ll r = k % students_per_team;
            __int128 sum_k = (__int128)q * p[i][students_per_team] + p[i][r];
            ll sum_up_to_k = (ll)sum_k;  
            ll numerator = t - sum_up_to_k;
            ll denominator = a[i][k % students_per_team];

            if (i == 0 || k > best_k || 
                (k == best_k && (ll)numerator * best_den > (ll)best_num * denominator)) {
                best_k = k;
                best_num = numerator;
                best_den = denominator;
                best_index = i;
            }
        }
        
        cout << best_index + 1 << ln;
    }

    time();
    return 0;
}