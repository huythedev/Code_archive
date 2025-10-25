// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI2"
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

const int K = 30; 

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n);
    ll total_sum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        total_sum += a[i];
    }

    vector<vector<ll>> len(K, vector<ll>(n));
    vector<vector<ll>> add(K, vector<ll>(n));
    vector<vector<int>> end_pos(K, vector<int>(n));

    vector<ll> a_doubled(2 * n);
    for (int i = 0; i < n; ++i) {
        a_doubled[i] = a_doubled[i + n] = a[i];
    }

    vector<ll> S(2 * n + 1, 0);
    for (int i = 0; i < 2 * n; ++i) {
        S[i + 1] = S[i] + a_doubled[i];
    }

    vector<int> next_jump(n, -1);
    stack<int> st;
    for (int j = 0; j < 2 * n; ++j) {
        while (!st.empty() && S[j + 1] > S[st.top() + 1]) {
            int i = st.top();
            st.pop();
            if (i < n && next_jump[i] == -1) {
                len[0][i] = j - i;
                add[0][i] = S[j + 1] - S[i + 1];
                end_pos[0][i] = j % n;
                next_jump[i] = j;
            }
        }
        st.push(j);
    }

    for (int k = 1; k < K; ++k) {
        for (int i = 0; i < n; ++i) {
            int pos1 = end_pos[k - 1][i];
            len[k][i] = len[k - 1][i] + len[k - 1][pos1];
            add[k][i] = add[k - 1][i] + add[k - 1][pos1];
            end_pos[k][i] = end_pos[k - 1][pos1];

            const ll CAP = 2e18;
            if (len[k][i] > CAP) len[k][i] = CAP;
            if (add[k][i] > CAP) add[k][i] = CAP;
        }
    }

    int m;
    cin >> m;

    int current_pos = n - 1; 

    while (m--) {
        ll b;
        cin >> b;

        ll total_moves = 0;

        for (int k = K - 1; k >= 0; --k) {
            if (add[k][current_pos] < b) {
                b -= add[k][current_pos];
                total_moves += len[k][current_pos];
                current_pos = end_pos[k][current_pos];
            }
        }

        // Final base jump
        total_moves += len[0][current_pos];
        current_pos = end_pos[0][current_pos];

        cout << total_moves << "\n";
    }
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