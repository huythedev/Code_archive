#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n, X;
    cin >> n >> X;

    vector<ll> a(n * 2);
    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        a[i + n] = a[i];
        if (a[i] >= X) {
            cout << 0;
            return 0;
        }
    }

    ll sum = 0;
    for (ll i = 0; i < n; ++i)
        sum += a[i];

    if (sum < X) {
        cout << 0;
        return 0;
    }

    ll min_length = LLONG_MAX;
    ll tmp = 0;
    ll start = 0;
    for (ll i = 0; i < n * 2; ++i) {
        tmp += a[i];
        while (tmp - a[start] >= X) {
            tmp -= a[start];
            start++;
        }
        if (tmp >= X) {
            min_length = min(min_length, (i - start + 1));
        }
    }

    if (min_length == LLONG_MAX)
        cout << -1;
    else
        cout << min_length;

    return 0;
}
