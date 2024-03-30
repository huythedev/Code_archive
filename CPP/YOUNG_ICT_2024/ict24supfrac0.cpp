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

ll CntZero(ll n) {
    ll res = 0;
    for(ll i = 5; i <= n; i *= 5) {
        res += n / i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N;
    cin >> N;

    ll res = 0;
    for(ll i = 1; i <= N; i++) {
        res += CntZero(i);
    }

    cout << res;

    return 0;
}