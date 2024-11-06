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

ll sumcs(ll n) {
    ll res = 0;
    while(n > 0) {
        res += n % 10;
        n /= 10;
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
        ll a, b, c;
        cin >> a >> b >> c;

        cout << a * cntdiv(a) * cntdiv(a) * sumcs(a) * sumcs(a) * sumcs(a) << " " << b * cntdiv(b) * cntdiv(b) * sumcs(b) * sumcs(b) * sumcs(b) << " " << c * cntdiv(c) * cntdiv(c) * sumcs(c) * sumcs(c) * sumcs(c) << ln;
    }

    return 0;
}