#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll n, m;
    cin >> n >> m;

    vector <ll> vec (n, 0);
    while (m--) {
        ll u, v, k;
        cin >> u >> v >> k;
        for (ll i = u; i <= v; ++i) {
            vec[i] += k;
        }
    }

    ll p;
    cin >> p;
    while (p--) {
        ll u, v;
        cin >> u >> v;
        ll res = LLONG_MIN;
        for (ll i = u; i <= v; ++i) {
            if (vec[i] > res) {
                res = vec[i];
            }
        }
        cout << res << endl;
    }
    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}
