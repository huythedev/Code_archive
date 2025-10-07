// Author: huythedev
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

int query(string st, int n) {
    cout << st << ' ' << n << ln;
    cout.flush();
    if (st == "throw") {
        int ans;
        cin >> ans;
        return ans;
    }
    return 0;
}

void solve() {
    int n;
    cin >> n;
    vector<int> boxes(n + 1), original(n + 1, 0), curr(n + 1, 0);
    for (int i = 1; i <= n; i++) 
        boxes[i] = i;

    if (n >= 2) {
        curr[n - 1] = (query("throw", n - 1) == 2 ? 1 : 2);
        original[boxes[n - 1]] = curr[n - 1];

        query("swap", n - 1);

        swap(boxes[n - 1], boxes[n]);
        swap(curr[n - 1], curr[n]);

        curr[n - 1] = (query("throw", n - 1) == 2 ? 1 : 2);
        original[boxes[n - 1]] = curr[n - 1];
    }
    
    for (int i = n - 2; i >= 1; i--) {
        vector<int> vec(n + 2, 0);
        for (int m = n; m >= i + 1; m--) {
            int next_pos = m + curr[m];
            if (next_pos > n)
                vec[m] = 1;
            else
                vec[m] = 1 + vec[next_pos];
        }

        int tmp = (i + 1 <= n ? 1 + vec[i + 1] : 1);
        int tmp2 = (i + 2 <= n ? 1 + vec[i + 2] : 1);

        if (tmp != tmp2) {
            curr[i] = (query("throw", i) == tmp ? 1 : 2);
            original[boxes[i]] = curr[i];
        } 
        else {
            query("swap", i);

            swap(boxes[i], boxes[i + 1]);
            swap(curr[i], curr[i + 1]);

            int ntmp = (i + 2 <= n ? 1 + vec[i + 2] : 1);
            int ntmp2 = (i + 3 <= n ? 1 + vec[i + 3] : 1);

            curr[i + 1] = (query("throw", i + 1) == ntmp ? 1 : 2);
            original[boxes[i + 1]] = curr[i + 1];
        }
    }

    cout << "! ";
    for (int k = 1; k <= n; k++)
        cout << original[k] << ' ';
    
    cout << ln;
    cout.flush();
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}