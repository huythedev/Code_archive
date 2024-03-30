#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

const ll MAXN = 1000;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

vector<ll> fib(MAXN);

void buildvec() {
    fib[0] = 1;
    fib[1] = 1;

    for(ll i = 2; i < MAXN; ++i) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    buildvec();

    int n;
    cin >> n;

    cout << fib[n - 1];

    return 0;
}
