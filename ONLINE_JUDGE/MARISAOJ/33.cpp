// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/33
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

    int n; cin >> n;
    vector<int> a(n);
    for(int &i : a) cin >> i;

    int longest_postive_subarray = 0, current_postive_subarray = 0;
    for(int i = 0; i < n; ++i) {
        if(a[i] > 0) {
            current_postive_subarray++;
            longest_postive_subarray = max(longest_postive_subarray, current_postive_subarray);
        } else {
            current_postive_subarray = 0;
        }
    }

    cout << longest_postive_subarray << ln;

    time();
    return 0;
}