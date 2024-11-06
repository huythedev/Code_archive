#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N; ll K; cin >> N >> K;

    map<ll, int> mp;
    for (int i = 0; i < N; ++i) {
        int t; cin >> t;
        mp[t]++;
    }

    ll res = 0;
    for (auto kv : mp) {
        if(kv.first > 0) {
            if(mp[K - kv.first] != 0) {
                
                res += (ll)kv.second * mp[K - kv.first];
                kv.first = LLONG_MIN;
            }
        }
        else {
            if(mp[kv.first - K] != 0)
                res += (ll)kv.second * mp[kv.first - K];
            if(mp[K - kv.first] != 0)
                res += (ll)kv.second * mp[K - kv.first];


            kv.first = LLONG_MIN;
        }
    }

    cout << res;
    return 0;
}
