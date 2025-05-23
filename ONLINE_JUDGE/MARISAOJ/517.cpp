// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/517
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

string sum(int a, int b) {
    return to_string(a + b);
}

int main() {
    fastio();
    docfile();

    int a, b; cin >> a >> b;
    string res = sum(a, b);
    reverse(res.begin(), res.end());

    while(res[0] == '0') res.erase(0, 1);

    cout << res;

    time();
    return 0;
}