#include <bits/stdc++.h>
using namespace std;

#define NAME "G"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;

// Precompute Fibonacci numbers, lengths, and counts of 1's
void precompute(int max_n, vector<ll>& lengths, vector<ll>& ones_count) {
    // Base cases
    lengths[0] = 1;  // |f_0| = 1
    lengths[1] = 1;  // |f_1| = 1
    ones_count[0] = 0; // number of 1's in f_0
    ones_count[1] = 1; // number of 1's in f_1

    for (int i = 2; i <= max_n; i++) {
        lengths[i] = (lengths[i - 1] + lengths[i - 2]) % MOD;
        ones_count[i] = (ones_count[i - 1] + ones_count[i - 2]) % MOD;
    }
}

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

int main() {
    fastio();
    docfile();

    int T;
    cin >> T;

    vector<int> queries(T);
    int max_n = 0;

    for (int i = 0; i < T; i++) {
        cin >> queries[i];
        max_n = max(max_n, queries[i]);
    }

    vector<ll> lengths(max_n + 1), ones_count(max_n + 1);
    precompute(max_n, lengths, ones_count);

    // Compute and print the beauty for each query
    for (int n : queries) {
        ll beauty = (lengths[n] * ones_count[n]) % MOD;
        cout << beauty << ln;
    }

    time();
    return 0;
}
