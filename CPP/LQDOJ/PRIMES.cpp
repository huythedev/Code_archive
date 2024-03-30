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

bool isPrime(ll n) {
    if(n < 2) return false;
    for(ll i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n;
    cin >> n;
    vector<ll> a(n);
    for(ll &i : a) {
        cin >> i;
    }

    ll CurrentMaxPrime = 0;

    for(ll i : a) {
        if(isPrime(i)) {
            CurrentMaxPrime = max(CurrentMaxPrime, i);
        }
    }

    cout << CurrentMaxPrime << ln;
    for(ll i = 0; i < n; i++) {
        if(a[i] == CurrentMaxPrime) {
            cout << i + 1 << " ";
        }
    }

    return 0;
}