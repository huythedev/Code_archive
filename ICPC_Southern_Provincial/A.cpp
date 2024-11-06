#include <bits/stdc++.h>
using namespace std;

#define NAME "A"
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

int T, n, m;
vector<vector<vector<ll>>> vec2;

void pre_process(int N) {
    vec2.assign(N + 1, vector<vector<ll>>(N + 1, vector<ll>(N + 1, 0)));
}

void update(int x, int y, int z, ll val, int N) {
    for (int i = x; i <= N; i += i & -i) {
        for (int j = y; j <= N; j += j & -j) {
            for (int k = z; k <= N; k += k & -k) {
                vec2[i][j][k] += val;
            }
        }
    }
}

ll query(int x, int y, int z) {
    ll res = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            for (int k = z; k > 0; k -= k & -k) {
                res += vec2[i][j][k];
            }
        }
    }
    return res;
}

ll solve(int x1, int y1, int z1, int x2, int y2, int z2) {
    return query(x2, y2, z2)
         - query(x1 - 1, y2, z2)
         - query(x2, y1 - 1, z2)
         - query(x2, y2, z1 - 1)
         + query(x1 - 1, y1 - 1, z2)
         + query(x1 - 1, y2, z1 - 1)
         + query(x2, y1 - 1, z1 - 1)
         - query(x1 - 1, y1 - 1, z1 - 1);
}

int main() {
    fastio();
    docfile();

    cin >> T;
    while (T--) {
        cin >> n >> m;
        pre_process(n);
        vector<vector<vector<ll>>> vec(n + 1, vector<vector<ll>>(n + 1, vector<ll>(n + 1, 0)));
       
        while (m--) {
            string type; cin >> type;
            if(type == "UPDATE") {
                int x, y, z; ll w; cin >> x >> y >> z >> w;
                ll val = w - vec[x][y][z];
                update(x, y, z, val, n);
                vec[x][y][z] = w;
            } 
            else if(type == "QUERY") {
                int x1, y1, z1, x2, y2, z2;
                cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
                cout << solve(x1, y1, z1, x2, y2, z2) << '\n';
            }
        }
    }

    time();
    return 0;
}