#include <bits/stdc++.h>
using namespace std;

#define NAME "for05"

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

ll tonguoc(ll n) {
    ll tong = 0;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            tong += i;
            if (i != n / i) {
                tong += n / i;
            }
        }
    }
    return tong;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n;
    cin >> n;

    if (tonguoc(n) == 2 * n) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }

    return 0;
}
