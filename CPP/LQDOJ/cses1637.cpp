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

int dembuoc(int n) {
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    
    for (int i = 1; i <= n; ++i) {
        string st = to_string(i);
        for (char c : st) {
            int digit = c - '0';
            if (digit != 0) {
                dp[i] = min(dp[i], 1 + dp[i - digit]);
            }
        }
    }
    
    return dp[n];
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;

    cout << dembuoc(n);

    return 0;
}