#include <bits/stdc++.h>
using namespace std;

#define NAME "str02"
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

    string s, t; cin >> s >> t;
    cout << s[0] << ' ' << t[t.sz - 1] << ' ';
    if(s[0] == t[t.sz - 1]) cout << "1";
    else cout << "0";

    time();
    return 0;
}