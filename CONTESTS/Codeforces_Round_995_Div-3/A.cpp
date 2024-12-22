#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

int main() {
    fastio();
    docfile();

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        int max_diff = INT_MIN;
        // Try all possible subsets using bitmask
        for (int mask = 0; mask < (1 << n); mask++) {
            int m = 0, s = 0;
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    m += a[i];
                    if (i < n-1) {
                        s += b[i+1];
                    }
                }
            }
            max_diff = max(max_diff, m - s);
        }

        cout << max_diff << ln;
    }

    time();
    return 0;
}