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

const int MOD = 1e9 + 7;

int powMod(int a, int e) {
    int ans = 1 % MOD;
    a %= MOD;
    while (e > 0) {
        if (e & 1) ans = (1LL * ans * a) % MOD;
        a = (1LL * a * a) % MOD;
        e >>= 1;
    }
    return ans;
}

int calc(int x, int m) {
    if (m == 0)
        return 1;
        
    int ans = x % MOD;
    --m;
    if (m <= 0) 
        return ans;

    int len = 32 - __builtin_clz(m);
    int tmp = min(x - 2, len);

    for (int i = 1; i <= tmp; ++i) {
        int exp = (m >> (i - 1)) - (m >> i);
        if (exp) 
            ans = (1LL * ans * powMod(i, exp)) % MOD;
    }

    if (x - 1 >= 1) {
        int exp = 0;
        if (x - 2 < 31)
            if ((x - 2) <= len - 1) 
                exp = (m >> (x - 2));
                
        if (exp) 
            ans = (1LL * ans * powMod((x - 1) % MOD, exp)) % MOD;
    }

    return ans;
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    for (int i = 0; i < n; ++i) 
        cin >> s[i];

    sort(s.begin(), s.end());

    int ans = 1;
    int rem = k;

    for (int x : s) {
        if (rem == 0) 
            break;

        if (x <= 31) {
            int L = 1 << (x - 1);
            
            if (rem >= L) {
                ans = (1LL * ans * calc(x, L)) % MOD;
                rem -= L;
                continue;
            }
        }

        ans = (1LL * ans * calc(x, rem)) % MOD;
        rem = 0;
    }

    cout << ans << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}