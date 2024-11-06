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

    ll N, M; cin >> N >> M;
    map<ll, ll> freq;
    ll maxfreq = 0;
    for(ll i = 0; i < M; ++i) {
        ll a, b; cin >> a >> b;
        for(int j = a; j <= b; ++j) {
            freq[j]++;
            maxfreq = max(maxfreq, freq[j]);
        }
    }

    ll res = 0;
    for(auto &kv : freq) 
        if(kv.second == maxfreq) {
            ++res;
            cout << kv.first << ln;
        }

    cout << res;

    return 0;
}