// Author: huythedev
// davul
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define NAME "BAI1"
#define ln "\n"

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME".INP")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}

void time() {
    cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC * 1.0 << "s." << ln;
}

const int maxn = 1e4 + 5;

int sum_div(int n) {
    int res = 0;
    for(int i = 1; i * i <= n; ++i) {
        if(n % i == 0) {
            res += i;
            if(n / i != i)
                res += n / i;
        }
    }
    return res;
}

int main() {
    fastio();
    docfile();

    int t; cin >> t;
    int res = 0;
    vector<int> vec(maxn);
    while (t--) {
        int n; cin >> n;
        if (2 * n <= sum_div(n)) {
            vec[res] = n;
            res++;
        }
    }

    cout << res << ln;
    for (int i = 0; i < res; ++i)
        cout << vec[i] << ln;

    time();
    return 0;
}