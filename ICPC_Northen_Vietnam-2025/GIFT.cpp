// Author: NBK.VaiLatXucXich
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

int calc2(int x, int y, int z, int q, int r) {
    return (x * q + y) * r + z;
}

int calc3(int* h, int n) {
    vector<int> vec(n + 1);
    int top = -1, best = 0;
    for (int k = 0; k <= n; ++k) {
        int cur;
        if (k < n) {
            cur = h[k];
        } 
        else {
            cur = 0;
        }

        while (top >= 0 && h[vec[top]] > cur) {
            int ht = h[vec[top--]];
            
            int left;
            if (top < 0) {
                left = 0;
            } 
            else {
                left = vec[top] + 1;
            }

            int width = k - left;
            int area = ht * width;

            best = max(best, area);
        }

        vec[++top] = k;
    }
    
    return best;
}

int calc(int A, int B, int L, int p, int q, int r, vector<bool> vec, int dir) {
    vector<int> vec2(A * B * L, 0), prev(B + 1, 0), cur(B + 1, 0);
    for (int k = 0; k < L; ++k) {
        fill(prev.begin(), prev.end(), 0);
        fill(cur.begin(), cur.end(), 0);
        for (int i = 1; i <= A; ++i) {
            cur[0] = 0;
            for (int j = 1; j <= B; ++j) {
                int x, y, z;
                if (dir == 0) {
                    x = i - 1;
                    y = j - 1;
                    z = k;
                } 
                else if (dir == 1) {
                    x = i - 1;
                    y = k;
                    z = j - 1;
                }
                else {
                    x = k;
                    y = i - 1;
                    z = j - 1;
                }

                if (vec[calc2(x, y, z, q, r)]) {
                    int m;
                    if (prev[j] < cur[j - 1])
                        m = prev[j];
                    else
                        m = cur[j - 1];
                    
                    if (prev[j - 1] < m)
                        m = prev[j - 1];
                    
                    cur[j] = m + 1;
                } 
                else {
                    cur[j] = 0;
                }

                int pos = ((i - 1) * B + (j - 1) ) * L + k;
                vec2[pos] = cur[j];
            }
            prev.swap(cur);
            fill(cur.begin(), cur.end(), 0);
        }
    }

    int res = 0;
    for (int pos = 0, tot = A * B; pos < tot; ++pos) {
        int* h = &vec2[pos * L];
        res = max(res, calc3(h, L));
    }

    return res;
}

void solve() {
    int p, q, r;
    cin >> p >> q >> r;

    vector<bool> vec(p * q * r, false);
    for (int y = 0; y < q; ++y) {
        for (int x = 0; x < p; ++x) {
            string s; 
            cin >> s;
            for (int z = 0; z < r; ++z) {
                if (s[z] == 'N')
                    vec[calc2(x, y, z, q, r)] = true;
                else
                    vec[calc2(x, y, z, q, r)] = false;
            }
        }
    }

    int res = 0;
    res = max(res, 4 * calc(p, q, r, p, q, r, vec, 0));
    res = max(res, 4 * calc(p, r, q, p, q, r, vec, 1));
    res = max(res, 4 * calc(q, r, p, p, q, r, vec, 2));

    cout << res << ln;
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