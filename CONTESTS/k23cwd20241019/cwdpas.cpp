#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdpas"
#define ln endl
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

string s, t;
int n, m;

bool is_prefix() {
    string t_prefix = t.substr(0, s.sz); 
    if(t_prefix == s) {
        return true;
    }
    return false;
}

bool is_suffix() {
    string t_suffix = t.substr(t.sz - s.sz, s.sz);
    if(t_suffix == s) {
        return true;
    }
    return false;
}

int main() {
    fastio();
    docfile();

    cin >> n >> m;
    cin >> s >> t;

    bool prefix = is_prefix(), suffix = is_suffix();

    if(prefix && suffix) cout << "0";
    else if(prefix) cout << "1";
    else if(suffix) cout << "2";
    else cout << "3";

    time();
    return 0;
}
