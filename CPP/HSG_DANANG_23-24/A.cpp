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

    vector<ll> vec(N);
    for(ll i = 0; i < N; ++i) 
        cin >> vec[i];

    sort(vec.rbegin(), vec.rend());

    ll res = 0;
    for(ll i = 0; i < K; ++i) 
        res += vec[i];

    cout << res;

    return 0;
}