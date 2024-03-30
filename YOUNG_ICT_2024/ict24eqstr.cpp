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

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string s, t;
    cin >> s >> t;

    if(s.length() == 1) {
        ll res = 0;
        for(char c : t) {
            if(c == s[0]) {
                res++;
            }
        }
        cout << res;
    }
    else if(s.length() == 2) {
        ll res = 0;
        for(ll i = 0; i < t.length() - 1; i++) {
            for(ll j = i + 1; j < t.length(); j++) {
                if(t[i] == s[0] && t[j] == s[1]) {
                    res = (res + 1) % MOD;
                }
            }
        }
        for(char c : s) {
            for(char c1 : t) {
                if(c == c1) {
                    res = (res + 1) % MOD;
                }
            }
        }
        cout << res;
    }
    else {
        cout << 0;
    }

    return 0;
}