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

ll minN(ll k) {
    ll low = 1, high = k;
    ll result = -1;

    while (low <= high) {
        ll mid = low + (high - low) / 2;
        ll sum = mid * (mid + 1);

        if (sum > k) {
            result = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll k;
    cin >> k;
    cout << minN(k);

    return 0;
}