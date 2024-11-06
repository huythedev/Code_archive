#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

int main() {
    fastio();
    docfile();

    int n, x; cin >> n >> x;

    vector<bool> dp(x + 1, 0);
    dp[0] = true;  

    for(int i = 0; i < n; ++i) {
        int A, B;
        cin >> A >> B;

        vector<bool> tmp(x + 1, 0);
        for(int j = 0; j <= x; ++j) {
            if(dp[j]) {
                for(int k = 0; k <= B && j + k * A <= x; ++k) {
                    tmp[j + k * A] = true;
                }
            }
        }

        dp = tmp;
    }

    if(dp[x]) 
        cout << "Yes";
    else 
        cout << "No";

    time();
    return 0;
}