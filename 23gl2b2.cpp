#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

const ll MOD = 1e9 + 7;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

vector<ll> buildPrefixSum(vector<ll> &a) {
    vector<ll> prefixSum(a.size() + 1, 0);
    for(ll i = 1; i <= a.size(); ++i) 
        prefixSum[i] = (prefixSum[i - 1] + a[i - 1]);
    return prefixSum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N;
    cin >> N;

    vector<ll> A(N);
    for(ll i = 0; i < N; ++i) 
        cin >> A[i];

    vector<ll> prefixSum = buildPrefixSum(A);

    ll res = 0;
    for(ll i = 0; i < N - 1; ++i) 
        res = (res + (prefixSum[N] - prefixSum[i + 1]) * A[i]) % MOD;

    cout << res;
    return 0;
}