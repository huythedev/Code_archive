#include <bits/stdc++.h>
using namespace std;

#define NAME "QUADRUPLE"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N;
    cin >> N;

    vector<ll> a(N);
    for(ll i = 0; i < N; ++i)  
        cin >> a[i];

    ll res = 0;
    for(ll i = 0; i < N - 3; ++i) {
        for(ll j = i + 1; j < N - 2; ++j) {
            for(ll k = j + 1; k < N - 1; ++i) {
                for(ll l = k + 1; l < N; ++l) {
                    if(a[i] - a[j] == a[k] - a[l])
                        ++res;
                }
            }
        }
    }

    cout << res;

    return 0;
}