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

ll POW(int a, ll b) {
    ll res = 1;
    for(ll i = 1; i <= b; ++i)
        res = (res * a) % MOD;
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int T;
    cin >> T;

    while(T--) {
        int a, b, c;
        cin >> a >> b >> c;

        ll tmp = b * c;
        cout << POW(a, tmp) << ln;
    }

    return 0;
}