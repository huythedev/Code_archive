#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const ll MOD = 1e9 + 7;
const ll MAXN = 1e6 + 6;

ll dp[MAXN][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll t; cin >> t;
    
    dp[1][1] = dp[1][2] = 1;
    for (ll i = 2; i < MAXN; i++) {
        dp[i][1] = (dp[i-1][1] * 4 % MOD + dp[i-1][2]) % MOD;
        dp[i][2] = (dp[i-1][1] + dp[i-1][2] * 2 % MOD) % MOD;
    }
    while(t--) {
        ll n; cin >> n;
        cout << (dp[n][1] + dp[n][2]) % MOD << ln;
    }

    return 0;
}