// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/24
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

int power_modulo(int a, int b, int c) {
    if(b == 0) return 1;
    if(b % 2 == 0) {
        int tmp = power_modulo(a, b / 2, c);
        return (tmp * tmp) % c;
    }
    return (a * power_modulo(a, b - 1, c)) % c;
}

int main() {
    fastio();
    docfile();

    int a, b, c; cin >> a >> b >> c;
    cout << power_modulo(a, b, c);

    time();
    return 0;
}