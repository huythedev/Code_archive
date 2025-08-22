// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "table3"
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

const int MAXSIZE = 400;
vector<vector<int>> table(MAXSIZE, vector<int>(MAXSIZE));

void solve() {
    int rowNums, colNums;
    cin >> rowNums >> colNums;

    for (int i = 0; i < rowNums; ++i) {
        for (int j = 0; j < colNums; ++j) {
            cin >> table[i][j];
        }
    }

    int ans = 0;

    for (int top = 0; top < rowNums; ++top) {
        for (int bottom = top; bottom < rowNums; ++bottom) {
            int height = bottom - top + 1;

            if (height * colNums <= ans) 
                continue;

            unordered_map<int,int> freq;
            freq.reserve(MAXSIZE);
            int dup = 0, left = 0;

            for (int right = 0; right < colNums; ++right) {
                for (int r = top; r <= bottom; ++r) {
                    int x = table[r][right];

                    if (++freq[x] == 2) 
                        ++dup;
                }

                while (dup > 0) {
                    for (int r = top; r <= bottom; ++r) {
                        int x = table[r][left];

                        if (--freq[x] == 1) 
                            --dup;
                    }
                    ++left;
                }
                
                ans = max(ans, height * (right - left + 1));
            }
        }
    }

    cout << ans << ln;
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