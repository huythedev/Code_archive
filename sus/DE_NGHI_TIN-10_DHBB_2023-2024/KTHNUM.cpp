// Author: huythedev
// Problem Link:

#include <bits/stdc++.h>
using namespace std;

#define NAME "KTHNUM"
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

const int MAXN = 1e5 + 5; 
int n, m;
int p[MAXN];
int k[MAXN];
int bit[MAXN]; 
vector<int> results;

void update(int idx, int delta) {
    for (; idx <= n; idx += idx & -idx) {
        bit[idx] += delta;
    }
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) {
        sum += bit[idx];
    }
    return sum;
}

int find_by_order(int target_k) {
    int idx = 0;
    int current_sum = 0;
    int max_pow2 = 1;
    while (max_pow2 * 2 <= n) {
        max_pow2 *= 2;
    }

    for (int bit_val = max_pow2; bit_val > 0; bit_val >>= 1) {
        if (idx + bit_val <= n) {
            if (current_sum + bit[idx + bit_val] < target_k) {
                current_sum += bit[idx + bit_val];
                idx += bit_val;
            }
        }
    }
    return idx + 1;
}

signed main() {
    fastio();
    docfile();

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    for (int i = 1; i <= n - m + 1; ++i) {
        cin >> k[i];
    }

    for (int i = 1; i <= m; ++i) {
        update(p[i], 1);
    }

    results.push_back(find_by_order(m - k[1] + 1));

    for (int i = 2; i <= n - m + 1; ++i) {
        update(p[i - 1], -1);
        update(p[i + m - 1], 1);

        results.push_back(find_by_order(m - k[i] + 1));
    }

    for (int i = 0; i < results.size(); ++i) {
        cout << results[i] << (i == results.size() - 1 ? "" : " ");
    }
    cout << ln;

    time();
    return 0;
}