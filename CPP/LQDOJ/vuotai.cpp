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

    int n, k, strongest = INT_MIN; cin >> n >> k;
    ll res = 0;

    int t;
    while(cin >> t) {
        strongest = max(strongest, t);
        res += t;
    }
    res -= strongest;

    cout << res + max(0, strongest - k) + 1;

    return 0;
}