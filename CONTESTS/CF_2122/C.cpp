// Author: huythedev
// Problem Link: 
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

bool comp(const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
    if (get<0>(a) != get<0>(b))
        return get<0>(a) < get<0>(b);
    return get<2>(a) < get<2>(b);
}

void solve() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> points(n);
    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        points[i] = make_tuple(x, y, i + 1);
        p[i] = i;
    }

    sort(p.begin(), p.end(), [&](int i, int j) {
        return get<0>(points[i]) < get<0>(points[j]);
    });

    vector<bool> isLeft(n + 1, false);
    for (int i = 0; i < n / 2; ++i) {
        isLeft[get<2>(points[p[i]])] = true;
    }

    sort(p.begin(), p.end(), [&](int i, int j) {
        return get<1>(points[i]) < get<1>(points[j]);
    });

    vector<int> vec1, vec2;
    for (int i = 0; i < n; ++i) {
        int tmp = get<2>(points[p[i]]);
        if (isLeft[tmp]) {
            vec1.push_back(tmp);
        } else {
            vec2.push_back(tmp);
        }
    }

    for (int i = 0; i < n / 2; ++i) {
        cout << vec1[i] << " " << vec2[n / 2 - 1 - i] << ln;
    }
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}