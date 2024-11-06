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

const int MAXN = 101, MAXX = 5e3 + 1;
const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N, X, t[MAXN];
    cin >> N >> X;
    for (int i = 1; i <= N; i++)
        cin >> t[i];
    sort(t + 1, t + N + 1);
    t[0] = t[1];

    ll dp[MAXN][MAXN][MAXX];
    dp[0][0][0] = 1;
    for(int i = 1; i <= N; i++) {
        for(int j = N; j >= 0; j--) {
            for(int k = X; k >= 0; k--) {
                ll cnt = dp[i - 1][j][k];
                int tmp = k + j * (t[i] - t[i - 1]);
                if (tmp > X) continue;

                dp[i][j][tmp] = (dp[i][j][tmp] + (j + 1) * cnt) % MOD;
                if (j != N) dp[i][j + 1][tmp] = (dp[i][j + 1][tmp] + cnt) % MOD;
                if (j != 0) dp[i][j - 1][tmp] = (dp[i][j - 1][tmp] + j * cnt) % MOD;
            }
        }
    }

    ll res = 0;
    for (int i = 0; i <= X; i++)
        res = (res + dp[N][0][i]) % MOD;
    cout << res << endl;
}