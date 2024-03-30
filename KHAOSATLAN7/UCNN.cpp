#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll m, n;
    cin >> n >> m;

    ll res = -1;
    for (ll i = 2; i <= min(m, n); ++i) {
        if (n % i == 0 && m % i == 0) {
            res = i;
            break;
        }
    }

    cout << res;
    return 0;
}