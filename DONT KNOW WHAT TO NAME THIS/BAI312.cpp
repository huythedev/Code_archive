// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI312"
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

bool isPrime(ll num) {
    if (num < 2) return false;
    for (ll i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

ll solve(string N) {
    ll res = -1;
    int len = N.size();
    for(int i = 1; i < (1 << len); ++i) {
        string tmp = "";
        for(int j = 0; j < len; ++j) {
            if(i & (1 << j)) {
                tmp += N[j];
            }
        }
        if(!tmp.empty()) {
            ll num = stoll(tmp);
            if(isPrime(num)) {
                res = max(res, num);
            }
        }
    }
    return res;
}

int main() {
    fastio();
    docfile();

    string N; cin >> N;

    cout << solve(N) << ln;

    time();
    return 0;
}