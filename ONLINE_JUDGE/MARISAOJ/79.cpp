// Author: huythedev
// Problem Link: https://marisaoj.com/problem/79
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "79"
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

void mem() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    ld mem_used = usage.ru_maxrss;
    if (mem_used < 1024.0) {
        cerr << ln << "Memory used: " << mem_used << " KB." << ln;
    }
    else if (mem_used >= (ld)1024.0 && mem_used < (1024.0 * 1024.0)) {
        cerr << ln << "Memory used: " << mem_used / 1024.0 << " MB." << ln;
    }
    else {
        cerr << "Memory used: " << (mem_used / 1024.0) / 1024.0 << " GB." << ln << "----------" << ln;
    }
}

signed main() {
    fastio();
    docfile();

    int n, queries; cin >> n >> queries;
    vector<int> a(n);
    vector<map<int, int> > freq(n + 1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[i + 1] = freq[i];
        freq[i + 1][a[i]]++;
    }

    // cout << ln;
    // for (unordered_map<int, int> i : freq) {
    //     for (pair <int, int> j : i) cout << j.first << ' ' << j.second << ln;
    //     cout << "----------" << ln;
    // }

    while (queries--) {
        int l, r, k; cin >> l >> r >> k;
        cout << freq[r][k] - freq[l - 1][k] << ln;
    }

    time();
    mem();
    return 0;
}