// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "POLLUTED"
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

signed main() {
    fastio();
    docfile();

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> freq(201, 0);
    for (int j = 0; j < d; ++j) {
        freq[a[j]]++;
    }

    int count = 0; 
    for (int i = d; i < n; ++i) {
        if (d % 2 == 1) {
            int k = (d + 1) / 2;
            int sum = 0;
            for (int x = 0; x <= 200; ++x) {
                sum += freq[x];
                if (sum >= k) {
                    int m = x;
                    if (a[i] >= 2 * m) {
                        count++;
                    }
                    break;
                }
            }
            int k1 = d / 2;
            int k2 = d / 2 + 1;
            int sum = 0;
            int m1 = -1, m2 = -1;
            for (int x = 0; x <= 200; ++x) {
                sum += freq[x];
                if (sum >= k1 && m1 == -1) {
                    m1 = x;
                }
                if (sum >= k2) {
                    m2 = x;
                    break;
                }
            }
            if (a[i] >= m1 + m2) {
                count++;
            }
        }
        freq[a[i - d]]--;
        freq[a[i]]++;
    }

    cout << count << ln;

    time();
    return 0;
}