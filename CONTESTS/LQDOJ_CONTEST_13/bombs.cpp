#include <bits/stdc++.h>
using namespace std;

#define NAME "bombs"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

const int MOD = 1e9 + 7;

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

    int n; cin >> n;

    vector<ll> x(n), r(n);
    for (int i = 0; i < n; ++i) 
        cin >> x[i] >> r[i];

    ll res = 0;
    int left = 0; 

    for (int i = 0; i < n; ++i) {
        ll left = x[i] - r[i];
        ll right = x[i] + r[i];

        while (left < n && x[left] < left) {
            left++;
        }

        int count = 0;
        for (int j = left; j < n && x[j] <= right; ++j) {
            count++;
        }

        ll ci = count; 
        res = (res + (i + 1) * ci) % MOD; 
    }

    cout << res;

    time();
    return 0;
}