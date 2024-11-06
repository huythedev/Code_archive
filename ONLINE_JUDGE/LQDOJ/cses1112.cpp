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

const int MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, m;
    cin >> n;
    string st;
    cin >> st;
    m = st.size();

    vector<int> dp(n + 1, 0);

    for (int i = 0; i < m; ++i) {
        dp[i] = 1;
    }

    for (int i = m; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i >= m) {
            dp[i] += dp[i - m];
            dp[i] %= MOD;
        }
    }

    cout << dp[n] << endl;

    return 0;
}