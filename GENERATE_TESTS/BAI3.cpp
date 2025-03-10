#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define NAME "BAI3"
#define ln "\n"

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
	cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s." << ln;
}

const int MOD = 666013;
vector<int> vec[100005];
int sz[100005];

ll tmp[100005], tmp2[100005];

ll power(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return res;
}

void precalc(int n) {
    tmp[0] = tmp2[0] = 1;
    for (int i = 1; i <= n; i++) {
        tmp[i] = tmp[i - 1] * i % MOD;
        tmp2[i] = power(tmp[i], MOD - 2);
    }
}

ll comb(int a, int b) {
    return tmp[a] * tmp2[b] % MOD * tmp2[a - b] % MOD;
}

void dfs(int u, int p, ll &res) {
    sz[u] = 1;
    ll ways = 1;
    int total = 0;
    for (int v : vec[u]) {
        if (v == p) continue;
        dfs(v, u, res);
        ways = ways * comb(total + sz[v], sz[v]) % MOD;
        total += sz[v];
        sz[u] += sz[v];
    }
    res = res * ways % MOD;
}

signed main() {
	fastio();
	docfile();

	int n;
    cin >> n;

    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }

    precalc(n);
    ll res = 1;
    dfs(1, -1, res);

    cout << res << "\n";

	time();
	return 0;
}