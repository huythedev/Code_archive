#include <bits/stdc++.h>
using namespace std;

#define NAME "RSUMAB"
#define ln '\n'

typedef long long ll;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

vector<ll> buildprefixsum(vector<ll> vec) {
    vector<ll> res(vec.size() + 1);
    res[0] = 0;
    for(ll i = 1; i < (int)res.size(); ++i)
        res[i] = res[i - 1] + vec[i -1];
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n, q; cin >> n >> q;

    vector<ll> x(n);
    for(ll i = 0; i < n; ++i)
        cin >> x[i];

    vector<ll> prefixsum = buildprefixsum(x);

    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            ll p, v; cin >> p >> v;
            ll diff = v - x[p - 1];
            for(int i = p; i < (int)prefixsum.size(); ++i)
                prefixsum[i] += diff;
            x[p - 1] += v; 
        }
        else {
            ll L, R; cin >> L >> R;

            cout << prefixsum[R] - prefixsum[L - 1] << ln;
        }
    }

    //cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    return 0;
}