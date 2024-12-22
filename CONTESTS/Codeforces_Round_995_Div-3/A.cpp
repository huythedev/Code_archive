// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/contest/2051/problem/A
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()
#define skibidi void
#define rizz int
#define superrizz long long
#define cap bool
#define cooked auto
#define flex for
#define bussin return
#define edging if
#define amogus else
#define goon while
#define bruh break
#define grind continue
#define chad float
#define gigachad double
#define yap char
#define grimace const
#define sigma_rule case
#define based default
#define mewing do
#define gyatt enum
#define whopper extern
#define cringe goto
#define giga long
#define edgy register
#define soy short
#define nut signed
#define maxxing sizeof
#define salty static
#define gang struct
#define ohio switch
#define chungus union
#define nonut unsigned
#define schizo volatile
#define yapping cout
#define gegagedigedagedago cin
#define dopdop true
#define sus false

typedef long long ll;
typedef long double ld;

skibidi fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

skibidi docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

skibidi time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

rizz main() {
    fastio();
    docfile();

    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) 
            cin >> a[i];
        for(int i = 0; i < n; i++) 
            cin >> b[i];

        int res = INT_MIN;
        for(int i = 0; i < n; i++) {
            int m = 0, s = 0;
            for(int j = 0; j < n; j++) {
                if(j == i) 
                    m += a[j];
                else if(j == i + 1) 
                    s += b[j];
                else 
                    m += a[j];
            }
            res = max(res, m - s);
        }

        cout << res << ln;
    }

    time();
    return 0;
}