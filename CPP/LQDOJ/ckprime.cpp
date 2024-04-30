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
    for(ll i = 2; i * i <= n; ++i) {
        if(n % i == 0) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll a, b; cin >> a >> b;

    if(isPrime((a + b) * (a - b)))
        cout << "YES";
    else 
        cout << "NO";

    return 0;
}