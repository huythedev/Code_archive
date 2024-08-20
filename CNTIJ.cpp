#include <bits/stdc++.h>

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll N, K;
    std::cin >> N >> K;

    std::vector<ll> a(N);
    for(ll i = 0; i < N; ++i) 
        std::cin >> a[i];
    
    std::map<ll, ll> dau;
    ll res = 0;
    for(ll i = 0; i < N; ++i) {
    	dau[a[i]]++;
    	res += dau[K - a[i] * a[i]];
    }

    std::cout << res;

    return 0;
}
