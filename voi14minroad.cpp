#include <bits/stdc++.h>
using namespace std;

#define NAME "voi14minroad"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

bool satisfy(const vector<ll>& tungs, const vector<ll>& trucs, int a, int b, ll L) {
    int tung_count = 0, truc_count = 0;
    int j = 0, k = 0;

    for (int i = 0; i < tungs.sz; ++i) {
        while (j < trucs.sz && trucs[j] < tungs[i] - L) ++j;
        if (j + b - 1 < trucs.sz && trucs[j + b - 1] <= tungs[i]) {
            tung_count++;
            if (tung_count >= a) return true;
        }
    }
    
    tung_count = 0; truc_count = 0;
    for (int i = 0; i < trucs.sz; ++i) {
        while (k < tungs.sz && tungs[k] < trucs[i] - L) ++k;
        if (k + a - 1 < tungs.sz && tungs[k + a - 1] <= trucs[i]) {
            truc_count++;
            if (truc_count >= b) return true;
        }
    }
    return false;
}

int main() {
    fastio();
    docfile();

    int n, a, b;
    cin >> n >> a >> b;

    vector<ll> tungs, trucs;
    for (int i = 0; i < n; ++i) {
        ll d, k;
        cin >> d >> k;
        if (k == 1) tungs.push_back(d);
        else trucs.push_back(d);
    }
    
    sort(tungs.begin(), tungs.end());
    sort(trucs.begin(), trucs.end());

    if (tungs.sz < a || trucs.sz < b) {
        cout << -1 << ln;
        return 0;
    }

    ll left = 0, right = 1e9, res = -1;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        if (satisfy(tungs, trucs, a, b, mid)) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    cout << res;

    time();
    return 0;
}
