// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/312
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

string decToBin(int n) {
    string res = "";
    while(n) {
        res += to_string(n % 2);
        n /= 2;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    fastio();
    docfile();

    int n; cin >> n;
    cout << decToBin(n);

    time();
    return 0;
}