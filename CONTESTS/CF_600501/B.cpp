// Author: huythedev
// Problem Link: https://codeforces.com/group/G0iFI97YZN/contest/600501/problem/B

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

int query(int i) {
    cout << "- " << i << ln;
    cout.flush();
    int x; cin >> x;
    return x;
}

signed main() {
    fastio();
    docfile();

    int t; cin >> t;
    while (t--) {
        int idx = 0, prev = 0;
        vector<int> bits(64, 0);

        cin >> prev;
        while (true) {
            if (prev == 0)
                break;

            int cnt = query((int)pow(2, idx));
            
            if (cnt == prev - 1) {
                bits[idx] = 1;
                idx++;
            } else {
                int next = idx + cnt - prev + 1;
                bits[next] = 1;
                
                int num = 0;
                for (int i = idx; i < next; ++i) {
                    num += (int)pow(2, i);
                }
                
                cnt = query(num);
                idx = next + 1;
            }
            prev = cnt;
        }
        int res = 0;
        for (int i = 0; i < 64; ++i) res += (int)pow(2, i) * bits[i];
        cout << "! " << res << ln;
        cout.flush();
    }

    time();
    return 0;
}