// Author: huythedev
// Problem Link: https://vjudge.net/contest/714787#problem/C
#include <bits/stdc++.h>
using namespace std;

#define NAME "C"
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

const int MAX_VAL = 1e6 + 5;
const int MAX_N_FACTORS = 11;

int dpf_count[MAX_VAL];
int cnt[MAX_N_FACTORS][MAX_VAL];

void precompute() {
    for (int i = 2; i < MAX_VAL; ++i) {
        if (dpf_count[i] == 0) {
            for (int j = i; j < MAX_VAL; j += i) {
                dpf_count[j]++;
            }
        }
    }

    for (int k = 0; k < MAX_N_FACTORS; ++k) {
        for (int x = 1; x < MAX_VAL; ++x) {
            cnt[k][x] = cnt[k][x - 1];
            if (dpf_count[x] == k) {
                cnt[k][x]++;
            }
        }
    }
}

signed main() {
    fastio();
    docfile();
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int a, b, n;
        cin >> a >> b >> n;
        if (n >= MAX_N_FACTORS) {
            cout << 0 << ln;
        } else {
            cout << cnt[n][b] - cnt[n][a - 1] << ln;
        }
    }

    time();
    return 0;
}