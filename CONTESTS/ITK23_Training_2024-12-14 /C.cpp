// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/573643/problem/C
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

    int n, k; cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int longest_subarray = INT_MIN, start_idx = 0, end_idx = 0;

    for(int i = 0; i < n - 1; ++i) {
        set<int> s;
        int subarray_length = 0;
        for(int j = i + 1; j < n; ++j) {
            s.insert(a[j]);
            if(s.sz > k) {
                break;
            }
            subarray_length++;
        }
        if(subarray_length > longest_subarray) {
            longest_subarray = subarray_length;
            start_idx = i;
            end_idx = i + subarray_length;
        }
    }

    cout << start_idx + 1 << " " << end_idx + 1 << endl;

    time();
    return 0;
}