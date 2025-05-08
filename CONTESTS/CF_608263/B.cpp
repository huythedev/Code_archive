// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/608263/problem/B
#include <bits/stdc++.h>
using namespace std;

#define NAME "B"
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

const ll LIM = (1LL << 32);

signed main() {
    fastio();
    docfile();

    int l; cin >> l;

    ll x = 0, curr = 1;
    stack<ll> s;
    bool overflow = false;

    for (int i = 0; i < l; ++i) {
        string command; cin >> command;

        if (command == "for") {
            int n; cin >> n;

            s.push(curr);
            
            if (curr < LIM) {
                ll tmp = curr * n;
                if (tmp >= LIM) {
                    curr = LIM;
                } else {
                    curr = tmp;
                }
            }
        } else if (command == "add") {
            if (overflow) {
                continue;
            }

            if (curr >= LIM) {
                overflow = true;
            } else {
                if (x >= LIM - curr) {
                    overflow = true;
                } else {
                    x += curr;
                }
            }
        } else if (command == "end") {
            if (!s.empty()) {
                curr = s.top();
                s.pop();
            }
        }
    }

    if (overflow) {
        cout << "OVERFLOW!!!" << ln;
    } else {
        cout << x << ln;
    }

    time();
    return 0;
}