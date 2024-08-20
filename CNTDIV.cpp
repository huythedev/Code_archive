#include <iostream>

typedef long long ll;
typedef long double ld;

ll demuoc(ll n) {
    ll cnt = 1;

    for(ll i = 2; i * i <= n; ++i) {
        ll tmp = 0;
        while(n % i == 0) {
            n /= i;
            ++tmp;
        }
        cnt *= (tmp + 1);
    }

    if(n > 1) {
        cnt *= 2;
    }

    return cnt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    
    ll t;
    std::cin >> t;
    while(t--) {
        ll n;
        std::cin >> n;
        ll res = demuoc(n);
        std::cout << res << std::endl;
    }

    return 0;
}
