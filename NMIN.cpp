#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll N;
    cin >> N;

    unordered_set<ll> diff;
    ll t;
    while (cin >> t) {
        diff.insert(t);
    }

    bool found = false;
    if (diff.find(0) == diff.end()) {
        cout << 0;
        found = true;
    } else {
        for (ll i = 1; i < N; ++i) {
            if (diff.find(i) == diff.end()) {
                cout << i;
                found = true;
                break;
            }
        }
    }

    if (!found) {
        cout << N;
    }

    return 0;
}
