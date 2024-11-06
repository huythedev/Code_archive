#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdlup"
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

    int n; cin >> n;
    string s; cin >> s;
    
    for(int i = 1; i < n; ++i) {
        int res = 0;
        for(int j = 0; j < n - i; ++j) {
            // cout << j << ' ' << j + i << ln; 
            if(j + i < n && s[j] != s[j + i]) {
                ++res;
            }
            else {
                break;
            }
        }
        cout << res << ln;
    }

    time();
    return 0;
}