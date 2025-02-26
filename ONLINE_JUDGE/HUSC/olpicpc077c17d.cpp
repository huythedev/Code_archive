// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc077c17d
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "olpicpc077c17d"
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

    int n, h;
    cin >> n >> h;
    vector<int> v1(h + 1, 0), v2(h + 1, 0);

    for (int i = 0; i < n; ++i) {
        int height;
        cin >> height;
        if (i % 2 == 0) {
            v2[height]++;
        } 
        else {
            v1[height]++;
        }
    }

    for (int i = h - 1; i > 0; --i) {
        v2[i] += v2[i + 1];
        v1[i] += v1[i + 1];
    }

    int x = INT_MAX, y = 0;
    for (int i = 1; i <= h; ++i) {
        int tmp = v2[i] + v1[h - i + 1];
        if (tmp < x) {
            x = tmp;
            y = 1;
        } 
        else if (tmp == x) {
            y++;
        }
    }

    cout << x << " " << y;

    time();
    return 0;
}