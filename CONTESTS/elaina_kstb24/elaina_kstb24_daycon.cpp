// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/elaina_kstb24_daycon

#include <bits/stdc++.h>
using namespace std;

#define NAME "DAYCON"
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

    int n; cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    int max_len = 1, curr_len = 1, start = 0, end = 0, temp_start = 0;
    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            ++curr_len;
        } else {
            if (curr_len > max_len) {
                max_len = curr_len;
                start = temp_start;
                end = i - 1;
            }
            curr_len = 1;
            temp_start = i;
        }
    }
    if (curr_len > max_len) {
        max_len = curr_len;
        start = temp_start;
        end = n - 1;
    }

    for (int i = start; i <= end; ++i) {
        cout << a[i] << " ";
    }

    time();
    return 0;
}