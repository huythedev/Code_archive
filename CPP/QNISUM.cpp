#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    ll res = 0;
    for (ll i = 1; i <= n; ++i) {
        if (i % 2 == 0) {
            res += (i + 1) * (i / 2);
        } else {
            res += (i + 1) * (i / 2) + (i / 2 + 1);
        }
    }

    cout << res;

    return 0;
}
