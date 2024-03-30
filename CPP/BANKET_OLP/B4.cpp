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
    
    vector<pair<ll, ll>> lr_list;
    
    for (ll i = 0; i < k; ++i) {
        ll l, r;
        cin >> l >> r;
        lr_list.push_back(make_pair(l, r));
    }

    vector<ll> vec(n + 1, 0); 
    vec[0] = 1;

    for (ll i = 1; i < n; ++i) {
        for (auto &lr : lr_list) {
            ll l = lr.first, r = lr.second;

            for (ll d = l; d <= r; ++d) {
                if (i - d >= 0) 
                    vec[i] += vec[i - d];
                
            }
        }
    }

    cout << vec[n - 1] << endl;

    return 0;
}