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

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    unordered_map<int, int> freq;
    int l = 0, r = 0, max_length = 0, start_idx = 0;

    for(r = 0; r < n; ++r) {
        freq[a[r]]++;
        while (freq.size() > k) {
            freq[a[l]]--;
            if (freq[a[l]] == 0) {
                freq.erase(a[l]);
            }
            l++;
        }
        if(r - l + 1 > max_length) {
            max_length = r - l + 1;
            start_idx = l;
        }
    }

    cout << start_idx + 1 << " " << start_idx + max_length << endl;

    time();
    return 0;
}