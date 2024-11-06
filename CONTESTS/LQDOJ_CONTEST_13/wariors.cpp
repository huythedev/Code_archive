#include <bits/stdc++.h>
using namespace std;

#define NAME "wariors"
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

    int n; 
    cin >> n;
    vector<int> pwr(n);
    for (int &i : pwr) cin >> i;

    unordered_map<int, ll> dp;  
    ll res = 0;         

    for(int i = 0; i < n; ++i) {
        int strength = pwr[i];
        
        ll tmp = strength;
        
        while (dp[tmp] > 0) {
            dp[tmp] = 0;  
            tmp *= 2;     
        }

        dp[tmp] += tmp;
        
        res = max(res, dp[tmp]);

        cout << res << ' ';
    }

    time();
    return 0;
}