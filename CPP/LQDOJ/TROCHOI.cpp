#include <bits/stdc++.h>
using namespace std;

#define NAME "TROCHOI"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

ll sumdiv(int n) {
    ll res = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            res += i;
            if (i != n / i) res += n / i;
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int q; cin >> q;
    vector<int> a(q);
    for (int i = 0; i < q; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++) {
        cout << sumdiv(a[i]) << ' ';
    }

    return 0;
}