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

const int MAX_N = 5000 + 5;
const int MAX_M = 5000 + 5;
const int INF = 1e9;

int n, m;
int x[MAX_N], a[MAX_M], b[MAX_M];
int dp[MAX_N][MAX_M];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    cin >> n >> m;
    for (int i = 1; i <= n; i++) 
        cin >> x[i];
    
    for (int i = 1; i <= m; i++) 
        cin >> a[i] >> b[i];
    

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) 
            dp[i][j] = INF;
        
    }
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i - 1][j];

            int tmp = INF;
            for (int k = 1; k <= i; k++) {
                if (k <= b[j]) {
                    int effort = abs(x[k] - a[j]) + dp[k - 1][j - 1];
                    tmp = min(tmp, effort);
                }
            }
            dp[i][j] = min(dp[i][j], tmp);
        }
    }

    int res = INF;
    for (int j = 1; j <= m; j++) {
        res = min(res, dp[n][j]);
    }

    if (res == INF) 
        cout << -1 << endl;
    else 
        cout << res << endl;

    return 0;
}