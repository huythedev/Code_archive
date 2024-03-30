#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    ll arr[n];
    for(ll i = 0; i < n; ++i) {
        ll t;
        cin >> t;
        arr[i] = t;
    }

    ll cnt = 0;
    for(ll j = 1; j <= n; ++j) {
        ll L = 0, R = 0;
        for(ll i = 0; i < j; ++i) {
            if(arr[i] > arr[j]) {
                ++L;
            }
        }
        for(ll k = j + 1; k < n; ++k) {
            if(k == n) {
                break;
            }
            if(arr[k] > arr[j]) {
                ++R;
            }
        }
        cnt += L * R;
    }

    cout << fixed << setprecision(6) << cnt / (n * (n - 1) * (n - 2) / 6 * 1.0);
    return 0;
}
