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
    for(ll i = 1; i*i <= n; i++) {
        if(n%i == 0) {
            if(i*i == n) res++;
            else res += 2;
        }
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
    for (ll i = 0; i < N; ++i) {
        ll a;
        cin >> a;
        res += a * cntdiv(a);
    }

    cout << res;


    return 0;
}
