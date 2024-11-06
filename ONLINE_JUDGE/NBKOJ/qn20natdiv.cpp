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

const int MAX = 1000000;

ll count_divisors[MAX + 1];
ll sum_divisors[MAX + 1];

void sieve() {
    for(ll i=1; i<=MAX; i++) {
        for(ll j=i; j<=MAX; j+=i) {
            count_divisors[j]++;
            sum_divisors[j] += i;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    sieve();
    int T;
    cin >> T;
    while(T--) {
        ll x, y;
        cin >> x >> y;
        ll count = 0, sum = 0;
        for(ll i=x; i<=y; i++) {
            count += count_divisors[i];
            sum += sum_divisors[i];
        }
        cout << count << " " << sum << "\n";
    }

    return 0;
}