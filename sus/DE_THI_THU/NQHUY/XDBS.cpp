// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "XDBS"
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

const int MAX_A = 100000;
vector<vector<int>> divisors(MAX_A + 1);

void precompute() {
    for (int d = 1; d <= MAX_A; ++d) {
        for (int multiple = d; multiple <= MAX_A; multiple += d) {
            divisors[multiple].push_back(d);
        }
    }
}

signed main() {
    fastio();
    docfile();
    precompute();

    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    vector<int> max_GCD_prefix(n, 0);
    vector<int> count_prefix(MAX_A + 1, 0);
    set<int, greater<int>> s_prefix;
    for (int m = 0; m < n; ++m) {
        for (int d : divisors[a[m]]) {
            count_prefix[d]++;
            if (count_prefix[d] == 2) {
                s_prefix.insert(d);
            }
        }
        if (m >= 1) {
            max_GCD_prefix[m] = *s_prefix.begin();
        }
    }

    vector<int> max_GCD_suffix(n, 0);
    vector<int> count_suffix(MAX_A + 1, 0);
    set<int, greater<int>> s_suffix;
    for (int m = n - 1; m >= 0; --m) {
        for (int d : divisors[a[m]]) {
            count_suffix[d]++;
            if (count_suffix[d] == 2) {
                s_suffix.insert(d);
            }
        }
        if (m <= n - 2) {
            max_GCD_suffix[m] = *s_suffix.begin();
        }
    }

    int ans = 0;
    for (int m = 1; m <= n - 3; ++m) {
        int current_sum = max_GCD_prefix[m] + max_GCD_suffix[m + 1];
        ans = max(ans, current_sum);
    }

    cout << ans << ln;

    time();
    return 0;
}