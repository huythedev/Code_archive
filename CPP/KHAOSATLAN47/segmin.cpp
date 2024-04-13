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
    int n = vec.size();

    vector<ll> res(n + 1);
    res[0] = 0;
    for(int i = 1; i <= vec.size(); ++i) 
        res[i] = res[i - 1] + vec[i - 1];

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll N, K; cin >> N >> K;
    vector<ll> a(N);
    for(ll i = 0; i < N; ++i) {
        cin >> a[i];
        if(a[i] == K) {
            cout << i + 1 << ' ' << 1;
            return 0;
        }
    }

    vector<ll> prefixsum = buildprefixsum(a);

    ll pos, length = LLONG_MAX;
    bool found = false;
    for(ll i = 1; i < N; ++i) {
        for(ll j = i + 1; j < N + 1; ++j) {
            if(prefixsum[j] - prefixsum[i - 1] == K && j - i + 1 < length) {
                pos = i;
                length = j - i + 1;
                found = true;
            }
        }
    }

    if(found) 
        cout << pos << ' ' << length;
    else 
        cout << 0;

    return 0;
}
