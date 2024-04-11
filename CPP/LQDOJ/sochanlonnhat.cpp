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

    ll n; cin >> n;
    vector<ll> chan, le;
    for(ll i = 0; i < n; ++i) {
        ll x; cin >> x;
        if(x % 2 == 0) 
            chan.push_back(x);
        else 
            le.push_back(x);
    }

    sort(chan.rbegin(), chan.rend());
    sort(le.rbegin(), le.rend());

    if(chan.size() > 1 && le.size() > 1)
        cout << max(chan[0] + chan[1], le[0] + le[1]);
    else if(chan.size() > 1)
        cout << chan[0] + chan[1];
    else if(le.size() > 1)
        cout << le[0] + le[1];
    else
        cout << -1;

    return 0;
}