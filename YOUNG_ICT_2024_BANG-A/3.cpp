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

    ll n, k;
    cin >> n >> k;

    ld res = 0;
    for(ll i = 1; i <= k / 2; ++i) {
        res += n / i;
        res += n / (k - i + 1);
    }

    cout << (ll)res;

    return 0;
}