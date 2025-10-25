// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI1"
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

void solve() {
    ll n;
    int m;
    cin >> n >> m;

    map<ll, ll> diff;

    for (int i = 0; i < m; ++i) {
        ll a, k;
        cin >> a >> k;

        ll rounds = a / n;
        if (rounds > 0) {
            diff[1] += rounds;
            diff[n + 1] -= rounds;
        }

        ll rem = a % n;
        if (rem == 0) {
            continue;
        }

        ll start = k;
        ll end_pos = k + rem - 1;

        if (end_pos <= n) {
            diff[start] += 1;
            diff[end_pos + 1] -= 1;
        } else {
            diff[start] += 1;
            diff[n + 1] -= 1;
            diff[1] += 1;
            diff[(end_pos % n) + 1] -= 1;
        }
    }

    diff[n + 1] += 0;

    map<ll, ll> counts;
    
    ll current_gifts = 0;
    ll last_pos = 1;

    for (map<ll, ll>::const_iterator it = diff.begin(); it != diff.end(); ++it) {
        ll pos = it->first;
        ll delta = it->second;
        ll num_students = pos - last_pos;

        if (num_students > 0) {
            counts[current_gifts] += num_students;
        }

        current_gifts += delta;
        last_pos = pos;

        if (pos > n) {
            break;
        }
    }

    map<ll, ll>::reverse_iterator it = counts.rbegin();
    if (it == counts.rend()) {
        cout << 0 << " " << n << ln;
    } else {
        cout << it->first << " " << it->second << ln;
    }
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