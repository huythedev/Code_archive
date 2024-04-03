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

ll cntdiv(ll n) {
    ll res = 0;
    for(ll i = 1; i <= n; i++) {
        if(n % i == 0)
            res++;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();


    int T;
    cin >> T;

    while(T--) {
        ll L, R;
        cin >> L >> R;

        ll res = 0;
        for(ll i = L; i <= R; i++) {
            res += cntdiv(i);
        }
        cout << res << ln;
    }

    return 0;
}