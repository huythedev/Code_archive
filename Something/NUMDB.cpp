#include <bits/stdc++.h>
using namespace std;

#define NAME "NUMDB"
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

const int max_sum_digits = 9 * 18;
bool isPrime[max_sum_digits + 5];
void sieve() {
    fill(isPrime, isPrime + max_sum_digits + 1, 1);
    isPrime[0] = isPrime[1] = 0;
    for(int i = 2; i <= max_sum_digits; ++i) {
        if(isPrime[i]) {
            for(int j = i * i; j <= max_sum_digits; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}

int sum_digit(int n) {
    int sum = 0;
    while(n) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

bool isCP(int n) {
    int tmp = sqrt(n);
    return tmp * tmp == n;
}

vector<ll> prefix(1e7 + 5, 0);
void build_prefix() {
    int tmp = 0;
    for(int i = 1; i <= 1e7; ++i) {
        if(isPrime[sum_digit(i)] && !isCP(i)) {
            tmp++;
        }
        prefix[i] = tmp;
    }
}

int main() {
    fastio();
    docfile();
    sieve();
    build_prefix();

    int tests; cin >> tests;
    while(tests--) {
        int l, r; cin >> l >> r;
        cout << prefix[r] - prefix[l - 1] << ln; 
    }

    time();
    return 0;
}