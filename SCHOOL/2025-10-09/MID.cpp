// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "MID"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

#define int ll

int solve_sub1(const vector<ll>& a) {
    int n = a.size();
    int cnt = 0;
    unordered_set<ll> mids;
    mids.reserve((size_t)n * n / 2);

    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j) {
            ll s = a[i] + a[j];
            if ((s & 1LL) == 0) mids.insert(s / 2);
        }

    for (auto x : a)
        if (mids.count(x)) ++cnt;

    return cnt;
}

// ---------- SUBTASK 2: n ≤ 3000, ai ≤ 2e4 ----------
int solve_sub24(const vector<ll>& a) {
    int n = a.size();
    int maxA = *max_element(a.begin(), a.end());
    vector<int> freq(maxA + 1);
    for (auto v : a) ++freq[v];
    int ans = 0;

    for (int v = 1; v <= maxA; ++v) {
        if (!freq[v]) continue;
        bool ok = false;
        int L = 1, R = maxA;
        int target = 2 * v;
        while (L <= R) {
            int sum = L + R;
            if (sum == target) {
                if ((L != R && freq[L] && freq[R]) ||
                    (L == R && freq[L] > 1)) { ok = true; break; }
                ++L; --R;
            } else if (sum < target) ++L;
            else --R;
        }
        if (ok) ans += freq[v];
    }
    return ans;
}

// ---------- SUBTASK 3: n ≤ 400, ai ≤ 1e9 ----------
int solve_sub3(vector<ll> a) {
    int n = a.size();
    sort(a.begin(), a.end());
    int cnt = 0;
    for (int k = 0; k < n; ++k) {
        ll target = 2 * a[k];
        int i = 0, j = n - 1;
        bool ok = false;
        while (i < j) {
            ll sum = a[i] + a[j];
            if (sum == target) { ok = true; break; }
            else if (sum < target) ++i;
            else --j;
        }
        if (ok) ++cnt;
    }
    return cnt;
}

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    for (auto &x : a) cin >> x;

    ll maxA = *max_element(a.begin(), a.end());
    int ans = 0;

    if (n <= 400 && maxA <= 20000)
        ans = solve_sub1(a);               // O(n^2)
    else if (n <= 3000 && maxA <= 20000)
        ans = solve_sub24(a);               // O(U^2) with U≤2e4
    else if (n <= 400 && maxA <= 1e9)
        ans = solve_sub3(a);               // O(n^2) (small n)
    else if (n <= 50000 && maxA <= 5000)
        ans = solve_sub24(a);               // O(U^2) with U≤5e3
    else
        ans = solve_sub3(a);               // fallback safe choice

    cout << ans;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}