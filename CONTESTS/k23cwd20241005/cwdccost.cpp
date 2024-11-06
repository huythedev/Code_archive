#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdccost"
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

int unpalindrome_chars(string s) {
    int n = s.sz;
    int res = 0;
    int l = 0, r = n - 1;
    while(l < r) {
        if(s[l] != s[r]) {
            ++res;
        }
        ++l;
        --r;
    }
    return res;
}

ll cost(string s, int b) {
    ll res = 0;
    res += 1ll * b * unpalindrome_chars(s);
    return res;
}

int main() {
    fastio();
    docfile();

    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;

    string tmp = s;
    ll res = LLONG_MAX;
    for(int i = 0; i <= n - 1; ++i) {
        ll tmp_cost = cost(tmp, b);
        tmp_cost += 1ll * a * i;
        // cout << tmp << ln;
        res = min(res, tmp_cost);
        tmp += tmp[0];
        tmp.erase(0, 1);
    }

    cout << res << ln;

    time();
    return 0;
}