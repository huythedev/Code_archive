// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/594115/problem/A
// davul
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

int n;
const int maxn = 5 * 1e5 + 5;
vector <int> a(maxn);
vector <ll> prefix_sum(maxn + 1);

signed main() {
    fastio();
    docfile();

    cin >> n;
    a.resize(n);
    prefix_sum.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i == 0) prefix_sum[0] = a[0];
        else prefix_sum[i] = prefix_sum[i - 1] + a[i];
    }

    // for (ll i : prefix_sum)
    //     cout << i << ' '; 
    // cout << ln;

    if (prefix_sum[n - 1] % 3 != 0) {
        cout << 0 << ln;
        return 0;
    }

    ll part_sum = prefix_sum[n - 1] / 3;
    ll count_part_sum = 0, res = 0;

    for (int i = 0; i < n - 1; ++i) {
        if (prefix_sum[i] == 2 * part_sum) {
            res += count_part_sum;
        }
        if (prefix_sum[i] == part_sum) {
            count_part_sum++;
        }
    }

    cout << res << ln;

    time();
    return 0;
}