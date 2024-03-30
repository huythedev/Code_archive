#include <iostream>
#include <vector>

typedef long long ll;
typedef long double ld;

void docfile() {
    freopen("CAU2.INP", "r", stdin);
    freopen("CAU2.OUT", "w", stdout);
}

ll sumcs(ll n) {
    ll res = 0;
    while(n > 0) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

bool isPrime(ll n) {
    for (ll i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return n > 1;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    //docfile();
    
    std::vector<ll> primes;

    ll tmp = 11;

    while(primes.size() < 10000) {
        if(isPrime(sumcs(tmp))) {
            primes.push_back(tmp);
        }
        ++tmp;
    }

    int n;
    std::cin >> n;
    std::cout << primes[n - 1];

    return 0;
}