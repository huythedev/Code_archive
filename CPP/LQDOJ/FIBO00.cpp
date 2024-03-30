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

    ll n;
    cin >> n;

    vector<ll> fibo(n);
    fibo[0] = 1;
    fibo[1] = 1;
    for(ll i = 2; i < n; i++) {
        fibo[i] = fibo[i - 1] + fibo[i - 2];
    }

    for(ll i : fibo) {
        cout << i << " ";
    }

    return 0;
}