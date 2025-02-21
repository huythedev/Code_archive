// Author: Perry
// davul
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define NAME "BAI3"
#define ln "\n"

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME".INP")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}

void time() {
    cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s." << ln;
}

int main() {
    fastio();
    docfile();
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<vector<int>> s_list(n);
    for (int s = 0; s < n; ++s) {
        int i = s + a[s];
        if (i < n) {
            s_list[i].push_back(s);
        }
    }

    vector<int> dp(n, 0);
    vector<int> max_dp(n, 0);

    for (int i = 0; i < n; ++i) {
        int current_max = 0;
        for (int s : s_list[i]) {
            int prev_max = (s > 0) ? max_dp[s - 1] : 0;
            int candidate = prev_max + (a[s] + 1);
            if (candidate > current_max) {
                current_max = candidate;
            }
        }
        dp[i] = current_max;
        if (i == 0) {
            max_dp[i] = dp[i];
        } else {
            max_dp[i] = max(max_dp[i - 1], dp[i]);
        }
    }

    cout << n - max_dp[n - 1];
    
    time();
    return 0;
}