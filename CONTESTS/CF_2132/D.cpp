// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

ll cntdigits(ll n) {
    if (n < 1) 
        return 0;

    int d = 0;
    ll tmp = n;
    while (tmp) {
        d++;
        tmp /= 10;
    }

    ll ans = 0, curr = 1;
    for (int len = 1; len < d; len++) {
        ans += 9 * curr * len;
        curr *= 10;
    }

    ans += (n - curr + 1) * d;
    return ans;
}

ll sumdigits(ll n) {
    if (n < 1) 
        return 0;

    ll ans = 0;
    ll curr = 1;
    while (curr <= n) {
        ll l = n / (curr * 10), r = n % curr;
        ll digit = (n / curr) % 10;

        ans += l * 45 * curr;
        ans += (digit * (digit - 1) / 2) * curr;
        ans += digit * (r + 1);

        curr *= 10;
    }

    return ans;
}

void solve() {
    ll k; cin >> k;

    ll l = 1, r = 1e15;

    while (l < r) {
        ll mid = l + (r - l) / 2;

        if (cntdigits(mid) >= k)
            r = mid;
        else
            l = mid + 1;
    }

    string st = to_string(l);
    ll n = k - cntdigits(l - 1);

    ll ans = sumdigits(l - 1);
    for (int i = 0; i < n; i++)
        ans += st[i] - '0';

    cout << ans << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}