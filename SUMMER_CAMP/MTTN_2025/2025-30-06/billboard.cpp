// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "billboard"
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

const int MAXN = 484;
const int MAXK = 25;

void solve() {
    int r, c; cin >> r >> c;
    int n = r * c;
    vector<string> grid(r);
    for (int i = 0; i < r; i++) 
        cin >> grid[i];
    
    vector<ll> A[MAXN];
    for (int i = 0; i < n; i++) {
        A[i].resize((n + 64) / 64, 0);

        int row = i / c, col = i % c;
        A[i][i / 64] |= (1LL << (i % 64));

        if (row > 0) {
            int nb = (row - 1) * c + col;
            A[i][nb / 64] |= (1LL << (nb % 64));
        }

        if (row < r - 1) {
            int nb = (row + 1) * c + col;
            A[i][nb / 64] |= (1LL << (nb % 64));
        }

        if (col > 0) {
            int nb = row * c + col - 1;
            A[i][nb / 64] |= (1LL << (nb % 64));
        }

        if (col < c - 1) {
            int nb = row * c + col + 1;
            A[i][nb / 64] |= (1LL << (nb % 64));
        }

        if (grid[row][col] == 'X') {
            A[i][n / 64] |= (1LL << (n % 64));
        }
    }
    
    vector<int> pivot(n, -1);
    int rank = 0;
    for (int col = 0; col < n; col++) {
        int row = -1;
        for (int i = rank; i < n; i++) {
            if ((A[i][col / 64] >> (col % 64)) & 1) {
                row = i;
                break;
            }
        }

        if (row == -1) 
            continue;

        swap(A[rank], A[row]);
        pivot[rank] = col;

        for (int i = 0; i < n; i++) {
            if (i != rank && (A[i][col / 64] >> (col % 64)) & 1) {
                for (int j = 0; j < A[i].size(); j++) {
                    A[i][j] ^= A[rank][j];
                }
            }
        }

        rank++;
    }
    
    for (int i = rank; i < n; i++) {
        if (A[i][n / 64] & (1LL << (n % 64))) {
            cout << "Damaged billboard." << ln;
            return;
        }
    }
    
    vector<ll> vec((n + 63) / 64, 0);
    for (int i = 0; i < rank; i++) {
        int col = pivot[i];
        if (A[i][n / 64] & (1LL << (n % 64))) {
            vec[col / 64] |= (1LL << (col % 64));
        }
    }
    
    vector<bool> free(n, true);
    for (int i = 0; i < rank; i++) 
        free[pivot[i]] = false;

    vector<vector<ll>> vec2;
    for (int i = 0; i < n; i++) {
        if (free[i]) {
            vector<ll> tmp((n + 63) / 64, 0);
            tmp[i / 64] |= (1LL << (i % 64));

            for (int j = 0; j < rank; j++) {
                int col = pivot[j];

                if (A[j][i / 64] & (1LL << (i % 64))) {
                    tmp[col / 64] |= (1LL << (col % 64));
                }
            }
            vec2.push_back(tmp);
        }
    }
    
    int min_k = 0;
    for (ll i : vec) 
        min_k += __builtin_popcountll(i);

    int k = vec2.size();
    if (k > 0 && k <= MAXK) {
        int combinations = 1 << k;

        for (int mask = 1; mask < combinations; mask++) {
            vector<ll> x = vec;

            for (int i = 0; i < k; i++) {
                if (mask & (1 << i)) {
                    for (int j = 0; j < x.size(); j++) {
                        x[j] ^= vec2[i][j];
                    }
                }
            }

            int cnt = 0;
            for (ll u : x) 
                cnt += __builtin_popcountll(u);

            min_k = min(min_k, cnt);
        }
    }

    cout << "You have to tap " << min_k << " tiles." << ln;
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