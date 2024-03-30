#include <bits/stdc++.h>
using namespace std;

#define NAME "SQTAB"
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

    ll n, k;
    cin >> n >> k;

    vector<ll> giatri(n * n);

    ll tmp = 0;
    for(ll i = 1; i <= n; ++i) {
        for(ll j = 1; j <= n; ++j) {
            giatri[tmp] = i * i + j * j;
            ++tmp;
        }
    }

    sort(giatri.begin(), giatri.end());
    
    cout << giatri[k - 1];

    return 0;
}