// Author: Perry (https://perrythedev.com)
// Problem Link: https://oj.vnoi.info/problem/coci1617_r5_unija
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "coci1617_r5_unija"
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

    int n;
    cin >> n;
    vector<int> w(n), h(n);
    vector<int> x, y1, y2, type;
    set<int> y_coords;

    for (int i = 0; i < n; ++i) {
        cin >> w[i] >> h[i];
        x.push_back(0);
        y1.push_back(0);
        y2.push_back(h[i]);
        type.push_back(1);
        x.push_back(w[i]);
        y1.push_back(0);
        y2.push_back(h[i]);
        type.push_back(-1);
        y_coords.insert(0);
        y_coords.insert(h[i]);
    }

    vector<int> vec(x.size());
    iota(vec.begin(), vec.end(), 0);
    sort(vec.begin(), vec.end(), [&](int i, int j) {
        return x[i] < x[j] || (x[i] == x[j] && type[i] < type[j]);
    });

    vector<int> y_compressed(y_coords.begin(), y_coords.end());
    unordered_map<int, int> y_map;
    for (int i = 0; i < y_compressed.size(); ++i) {
        y_map[y_compressed[i]] = i;
    }

    vector<int> cnt(y_compressed.size(), 0);
    vector<int> len(y_compressed.size() - 1, 0);

    int prev_x = 0;
    ll res = 0;

    for (int idx : vec) {
        int curr_x = x[idx];
        int curr_y1 = y_map[y1[idx]];
        int curr_y2 = y_map[y2[idx]];

        ll width = curr_x - prev_x;
        ll height = 0;
        for (int i = 0; i < len.size(); ++i) {
            if (cnt[i] > 0) {
                height += y_compressed[i + 1] - y_compressed[i];
            }
        }
        res += width * height;

        for (int i = curr_y1; i < curr_y2; ++i) {
            cnt[i] += type[idx];
        }

        prev_x = curr_x;
    }

    cout << res;

    time();
    return 0;
}