// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "KINTER"
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

struct Segment {
    int l, r;
};

bool comp(const Segment& a, const Segment& b) {
    return a.l < b.l;
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<Segment> segments(n);
    for (int i = 0; i < n; ++i) {
        cin >> segments[i].l >> segments[i].r;
    }

    if (k == 1) {
        ll max_len = 0;
        for (int i = 0; i < n; ++i) {
            max_len = max(max_len, (ll)segments[i].r - segments[i].l);
        }
        cout << max_len << ln;
        return;
    }

    sort(segments.begin(), segments.end(), comp);

    priority_queue<int, vector<int>, greater<int>> pq;

    ll res = 0;

    for (int i = 0; i < n; ++i) {
        pq.push(segments[i].r);

        if (pq.size() > k) {
            pq.pop();
        }

        if (pq.size() == k) {
            int L = segments[i].l;
            int R = pq.top();

            ll curr_len = (ll)R - L;
            if (curr_len > res) {
                res = curr_len;
            }
        }
    }

    cout << res << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
