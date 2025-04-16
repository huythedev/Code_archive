// Author: huythedev (https://huythedev.com)^
#include <bits/stdc++.h>
using namespace std;

#define NAME "demso"
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

const ll mod = 1e9 + 7;
pair<ll, ll> dp[20][5433][181];
ll kq, l, r, coso[20];
vector<int> dg;
int q, k, P[11];
bool is_coprime[5433][181];  

pair<ll, ll> get(int pos, int sum1, int sum2, bool dabe) {
    if (pos == -1 && (is_coprime[sum1][sum2])) return pair<ll, ll>{0, 1}; 
    else if (pos == -1) return pair<ll, ll>{0, 0};

    if (dp[pos][sum1][sum2] != pair<ll, ll>{-1, 0} && dabe) return dp[pos][sum1][sum2];

    pair<ll, ll> res = {0, 0};
    for (int i = 0; i <= max(dg[pos], dabe * 9); i++) {
        pair<ll, ll> cc = get(pos - 1, sum1 + P[i], sum2 + i, dabe | (i < dg[pos]));
        res.first = ((res.first + cc.first) % mod + ((i * coso[pos]) % mod * (cc.second % mod)) % mod) % mod;
        res.second += cc.second;
    }
    if (dabe) dp[pos][sum1][sum2] = res;
    return res;
}

ll call(ll x) {
    if (x == 0) return 0;
    dg.clear();
    for (; x > 0; x /= 10) dg.push_back(x % 10);
    return get(dg.size() - 1, 0, 0, 0).first;
}

int main() {
    fastio();
    docfile();

    coso[0] = 1;
    P[0] = 0;

    for (int i = 1; i <= 9; i++) P[i] = i * i + P[i - 1];
    for (int i = 1; i <= 18; i++) coso[i] = coso[i - 1] * 10 % mod;

    for (int i = 0; i <= 5432; i++) {
        for (int j = 0; j <= 180; j++) {
            if (gcd(i, j) == 1) is_coprime[i][j] = 1;  
            else is_coprime[i][j] = 0;
        }
    }

    for (int i = 0; i <= 19; i++) {
        for (int j = 0; j <= 5432; j++) {
            for (int k = 0; k <= 180; k++) dp[i][j][k] = {-1, 0};
        }
    }

    cin >> q;
    for (int i = 1; i <= q; i++) {
        cin >> l >> r;
        cout << (call(r) - call(l - 1) + mod * mod) % mod << "\n";
    }

    time();
    return 0;
}
