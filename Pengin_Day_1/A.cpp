#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (ll i = 0; i < n; ++i) 
        cin >> a[i];

    map<ll, ll> cnt;
    ll prefix_sum = 0, res = 0;

    for(ll i = 0; i < n; ++i) {
        prefix_sum += a[i];
        
        if(prefix_sum == x)
            res++;
            
        if(cnt.find(prefix_sum - x) != cnt.end())
            res += cnt[prefix_sum - x];

        cnt[prefix_sum]++;
    }

    cout << res;

    return 0;
}
