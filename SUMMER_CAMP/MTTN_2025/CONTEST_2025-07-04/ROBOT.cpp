// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "ROBOT"
#define ln "\n"

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME".INP")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}

void time() {
    cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC * 1.0 << "s." 
         << ln;
}

const int INF = 1e9;

void subtask1(string s, int k) {
    int res = 0;
    bool positive = true;
    for (char c : s) {
        if (c == 'M') {
            if (positive) ++res;
            else --res;
        }
        if (c == 'D')
            positive = !positive;
    }
    cout << abs(res) << ln;
}

void solve() {
    // char sus; cin >> sus;
    int n, k; cin >> n >> k;
    string s; cin >> s;
    
    cerr << "n = " << n << " k = " << k << ln;
    cerr << "s = " << s << ln;

    bool subtask2 = true;
    for (char c : s) {
        if (c == 'M') subtask2 = false;
    }

    if (subtask2) {
        cout << 0 << ln;
        return;
    }

    if (k == 0) {
        subtask1(s, k);
        return;
    }

    vector<vector<set<int>>> dp[2];
    dp[0].assign(k + 1, vector<set<int>>(2));
    dp[1].assign(k + 1, vector<set<int>>(2));

    dp[0][0][0].insert(0);

    int curr = 0;
    for (int i = 1; i <= n; ++i) {
        curr = i % 2;
        int prev = (i - 1) % 2;
        for(int j=0; j<=k; ++j) {
            dp[curr][j][0].clear();
            dp[curr][j][1].clear();
        }

        for (int j = 0; j <= k; ++j) {
            char job = s[i - 1];
            if (job == 'M') {
                for (int pos : dp[prev][j][0]) 
                    dp[curr][j][0].insert(pos + 1);
                for (int pos : dp[prev][j][1])
                    dp[curr][j][1].insert(pos - 1);
            } 
            else {
                for (int pos : dp[prev][j][0]) 
                    dp[curr][j][1].insert(pos);
                for (int pos : dp[prev][j][1]) 
                    dp[curr][j][0].insert(pos);
            }

            if (j > 0) {
                char job2 = (s[i - 1] == 'M' ? 'D' : 'M');
                if (job2 == 'M') {
                    for (int pos : dp[prev][j - 1][0])
                        dp[curr][j][0].insert(pos + 1);
                    for (int pos : dp[prev][j - 1][1])
                        dp[curr][j][1].insert(pos - 1);
                }
                else {
                    for (int pos : dp[prev][j - 1][0]) 
                        dp[curr][j][1].insert(pos);
                    for (int pos : dp[prev][j - 1][1]) 
                        dp[curr][j][0].insert(pos);
                }
            }
        }
    }

    int res = 0, idx = n % 2;
    for (int j = 0; j <= k; ++j) {
        if ((k - j) % 2 == 0) {
            for (int pos : dp[idx][j][0]) {
                res = max(res, abs(pos));
            }
            for (int pos : dp[idx][j][1]) {
                res = max(res, abs(pos));
            }
        }
    }
    
    cout << res << ln;
}

int main() {
    fastio();
    docfile();

    int t = 1; 
    cin >> t;
    while (t--) {
        string tmp; 
        getline(cin, tmp);
        solve();
    }

    time();
    return 0;
}
