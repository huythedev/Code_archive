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

const int MOD = 1e9 + 7;
const int MAX_PRIME = 10000000;

vector<bool> is_prime(MAX_PRIME + 1, true);
vector<int> prime_count(MAX_PRIME + 1, 0);

void sieve() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= MAX_PRIME; i++) {
        if (is_prime[i]) {
            for (int j = i; j <= MAX_PRIME; j += i) {
                is_prime[j] = false;
                prime_count[j]++;
            }
        }
    }
}

ll solve(ll L, ll R) {
    sieve();

    ll result = 1;
    for (int p = 2; p <= MAX_PRIME; p++) {
        if (is_prime[p]) {
            ll curr_lcm = 1;
            for (ll i = max(L, (ll)p); i <= R; i++) {
                if (i % p == 0) {
                    curr_lcm = lcm(curr_lcm, i);
                    if (curr_lcm > R) {
                        break;
                    }
                }
            }
            result = (result * curr_lcm) % MOD;
        }
    }

    for (ll i = L; i <= R; i++) {
        if (i > MAX_PRIME && prime_count[MAX_PRIME] == 1) {
            result = (result * i) % MOD;
        }
    }

    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    ll L, R;
    cin >> L >> R;
    cout << solve(L, R) << endl;
    return 0;
}