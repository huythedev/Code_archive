// Author: huythedev
// Problem Link: https://vjudge.net/contest/714787#problem/E
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

const int MAXN = 11000000;
int spf[MAXN + 5];
vector<ll> vec;

void precompute() {
    if (!vec.empty()) {
        return;
    }

    for (int i = 1; i <= MAXN; ++i) {
        spf[i] = i;
    }

    for (int i = 2; i * i <= MAXN; ++i) {
        if (spf[i] == i) {
            for (int j = i * i; j <= MAXN; j += i) {
                if (spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    vec.reserve(2e7);

    for (int i = 6; i <= MAXN; ++i) {
        if (vec.size() == 2e7) {
            break;
        }

        int p = spf[i];
        if (p == i || p == 0) continue;

        int tmp = i / p;

        if (p < tmp && spf[tmp] == tmp) {
            vec.push_back(i);
        }
    }
}

signed main() {
    fastio();
    docfile();
    precompute();

    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        if (k > 0 && k <= (int)vec.size()) {
            cout << vec[k - 1] << ln;
        } else {
            cout << vec[k - 1] << ln;
        }
    }

    time();
    return 0;
}