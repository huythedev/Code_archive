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

ll solve(ll N) {
    vector<ll> dp(N + 1, 1e18 + 5);

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        ll tmp = i;
        while (tmp) {
            ll d = tmp % 10;
            dp[i] = min(dp[i], 1 + dp[i - d]);
            tmp /= 10;
        }
    }
    return dp[N];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;
    cout << solve(n);

    return 0;
}
