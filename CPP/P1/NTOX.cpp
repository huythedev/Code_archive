#include <bits/stdc++.h>
using namespace std;

#define NAME "NTOX"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isPrime(int n) {
    if (n == 2 || n == 3)
        return true;
    if (n < 3 || n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i += 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    vector<int> primes;

    for (int i = 2; i <= (int)1e6; ++i)
        if (isPrime(i))
            primes.push_back(i);
    
    int T; cin >> T;
    while (T--) {
        int N; cin >> N;

        if (N <= 2) {
            cout << -1 << ln;
            continue;
        }

        auto it = lower_bound(primes.begin(), primes.end(), N);
        cout << *(--it) << ln;
    }

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";

    return 0;
}
