// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/phuccnh_dptower
// davul
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

bool compare(tuple<int, int, int> a, tuple<int, int, int> b) {
    if (get<0>(a) != get<0>(b)) {
        return get<0>(a) > get<0>(b);
    }

    if (get<1>(a) != get<1>(b)) {
        return get<1>(a) > get<1>(b);
    }

    return get<2>(a) > get<2>(b);
}

int main() {
    fastio();
    docfile();

    int n;
    cin >> n;
    vector<tuple<int, int, int>> bricks(n);
    for (int i = 0; i < n; ++i) {
        int l, w, h;
        cin >> l >> w >> h;
        bricks[i] = make_tuple(l, w, h);
    }

    sort(bricks.begin(), bricks.end(), compare);

    vector<int> dp(n), h(n);
    int x = 0, y = 0;

    for (int i = 0; i < n; ++i) {
        dp[i] = 1;
        h[i] = get<2>(bricks[i]);
        for (int j = 0; j < i; ++j) {
            if (get<0>(bricks[i]) < get<0>(bricks[j]) && get<1>(bricks[i]) < get<1>(bricks[j])) {
                if (dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    h[i] = h[j] + get<2>(bricks[i]);
                }
            }
        }
        if (dp[i] > x) {
            x = dp[i];
            y = h[i];
        } 
        else if (dp[i] == x) {
            y = max(y, h[i]);
        }
    }

    cout << x << " " << y << ln;

    time();
    return 0;
}