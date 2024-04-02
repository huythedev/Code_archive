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

vector<ll> buildprefixsum(vector<ll> vec) {
    vector<ll> res(vec.size() + 1);
    res[0] = 0;
    for(int i = 1; i <= vec.size(); ++i)
        res[i] = res[i - 1] + vec[i - 1];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N, K;
    cin >> N >> K;

    vector<ll> a(N);
    for(ll i = 0; i < N; ++i)
        cin >> a[i];

    vector<ll> prefixsum = buildprefixsum(a);
    ll res = 0;
    for(int i = 0; i < N - K; i += K) 
        res = max(res, prefixsum[i + K] - prefixsum[i]); 

    cout << res;

    return 0;
}