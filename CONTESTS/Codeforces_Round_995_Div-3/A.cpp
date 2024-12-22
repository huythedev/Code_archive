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
        for (int i = 0; i < n; i++) {
            int m = 0, s = 0;
            for (int j = 0; j < n; j++) {
                if (j == i) {
                    m += a[j];
                } else if (j == i + 1) {
                    s += b[j];
                } else {
                    m += a[j];
                }
            }
            max_diff = max(max_diff, m - s);
        }

        cout << max_diff << ln;
    }

    time();
    return 0;
}