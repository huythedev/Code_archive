// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "gogovoi_ctin_countprnumber"
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

const int LIM = 100;
vector<bool> primes(LIM, true);

void sieve() {
    primes[0] = primes[1] = false;
    for (int i = 2; i * i < LIM; ++i) {
        if (primes[i]) {
            for (int j = i * i; j < LIM; j += i) {
                primes[j] = false;
            }
        }
    }
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        
        reverse(s.begin(), s.end());

        while (s.length() > 1 && s[0] == '0') s.erase(0, 1);

        int x = stoi(s);
        if (primes[x]) {
            // cout << x << ln;
            ++ans;
        }
    }

    cout << ans << ln;
}

signed main() {
    docfile();
    fastio();
    sieve();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}