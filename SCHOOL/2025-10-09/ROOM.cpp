// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "ROOM"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

struct Job {
    int a, b;
    ll c;
};

void solve() {
    int n;
    cin >> n;
    vector<Job> jobs(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> jobs[i].a >> jobs[i].b >> jobs[i].c;

    sort(jobs.begin() + 1, jobs.end(), [](const Job& x, const Job& y){
        if (x.b != y.b) return x.b < y.b;
        return x.a < y.a;
    });

    vector<int> ends(n + 1);
    for (int i = 1; i <= n; ++i) ends[i] = jobs[i].b;

    vector<ll> dp(n+1, 0);

    for (int i = 1; i <= n; ++i) {
        int p = int(upper_bound(ends.begin() + 1, ends.begin() + n + 1, jobs[i].a) - (ends.begin())) - 1;
        dp[i] = max(dp[i - 1], dp[p] + jobs[i].c);
    }

    cout << dp[n] << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}