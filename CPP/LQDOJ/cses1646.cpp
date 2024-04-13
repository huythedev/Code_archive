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

vector<ll> buildprefixsum(vector<ll> &a) {
    vector<ll> res(a.size() + 1, 0);
    res[0] = 0;
    for(ll i = 1; i <= a.size(); ++i) 
        res[i] = res[i - 1] + a[i - 1];
    
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, q; cin >> n >> q;
    vector<ll> a(n);
    for(ll i = 0; i < n; ++i) cin >> a[i];

    vector<ll> prefixsum = buildprefixsum(a);
    while(q--) {
        int l, r; cin >> l >> r;
        l--; r--;
        cout << prefixsum[r + 1] - prefixsum[l] << ln;
    }

    return 0;
}