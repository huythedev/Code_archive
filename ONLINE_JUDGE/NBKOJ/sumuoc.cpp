#include <bits/stdc++.h>
using namespace std;

#define NAME "SUMUOC"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

ll sumdiv(ll n) {
    ll sum = 0;
    for (ll i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i) sum += i;
            else sum += i + n / i;
        }
    }
    return sum;
}

int main() {
    fastio();
    docfile();

    ll n; cin >> n;
    cout << sumdiv(n);

    time();
    return 0;
}