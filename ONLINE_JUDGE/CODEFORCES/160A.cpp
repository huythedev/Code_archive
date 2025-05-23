// Author: huythedev (https://huythedev.com)
// Problem Link: https://codeforces.com/problemset/problem/160/A

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

signed main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<int> coins(n);
    int total_sum = 0;

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
        total_sum += coins[i];
    }

    sort(coins.rbegin(), coins.rend());

    int my_sum = 0, count = 0;
    for (int i = 0; i < n; ++i) {
        my_sum += coins[i];
        count++;
        if (my_sum > total_sum - my_sum) {
            break;
        }
    }

    cout << count << ln;

    time();
    return 0;
}