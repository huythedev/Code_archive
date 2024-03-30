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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N, K;
    cin >> N >> K;

    if(K > N) {
        cout << 0;
        return 0;
    }

    vector<ll> A(N);
    for(ll i = 0; i < N; ++i) 
        cin >> A[i];

    ll res = LLONG_MIN;

    for(ll i = K; i < N; ++i) {
       for(ll j = 0; j <= i - K; ++j) {
            res = max(res, A[i] + A[j]);
       }
    }
    cout << res;

    return 0;
}