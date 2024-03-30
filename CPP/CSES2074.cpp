#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n + 1); 
    vector<ll> prefix_sum(n + 1, 0);

    for (ll i = 1; i <= n; ++i) {
        cin >> a[i];
        prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    for (ll i = 0; i < m; ++i) {
        ll t, l, r;
        cin >> t >> l >> r;

        if (t == 1) { 
            while (l < r) {
                swap(a[l], a[r]);
                ++l;
                --r;
            }
            for (ll j = 1; j <= n; ++j) {
                prefix_sum[j] = prefix_sum[j - 1] + a[j];
            }
        } else if (t == 2) { 
            cout << prefix_sum[r] - prefix_sum[l - 1] << "\n";
        }
    }

    return 0;
}
