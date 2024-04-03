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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N, Q;
    cin >> N >> Q;

    ll sumvec = 0;
    vector<ll> a(N);
    for(ll i = 0; i < N; i++) {
        cin >> a[i];
        sumvec += a[i];
    }

    while(Q--) {
        ll l, r;
        cin >> l >> r;

        if(r - l + 1 % 2 != 0)
            sumvec += 1;
    }

    cout << sumvec;

    return 0;
}