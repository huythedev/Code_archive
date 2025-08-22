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

void solve() {
    int n, s;
    cin >> n >> s;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int sum = 0;
    for (int x : a) {
        sum += x;
    }

    if (s < sum) {
        for (int i = 0; i < n; i++) {
            cout << a[i] << ' ';
        }
        cout << ln;
    } 
    else if (s == sum) {
        cout << -1 << ln;
    } 
    else if (s == sum + 1) {
        int c0 = 0, c1 = 0, c2 = 0;
        for (int x : a) {
            if (x == 0) {
                c0++;
            }
            else if (x == 1) {
                c1++;
            }
            else {
                c2++;
            }
        }
        
        for (int i = 0; i < c0; i++) 
            cout << "0 ";

        for (int i = 0; i < c2; i++) 
            cout << "2 ";

        for (int i = 0; i < c1; i++) {
            cout << "1 ";
        }
        
        cout << ln;
    } 
    else {
        cout << -1 << ln;
    }
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}