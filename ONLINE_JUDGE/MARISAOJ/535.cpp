// Author: Perry (https://perrythedev.com)
// Problem Link: https://marisaoj.com/problem/535
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

int main() {
    fastio();
    docfile();

    double a, b; char operation; cin >> a >> operation >> b;
    double res;
    switch(operation) {
        case '+': res = a + b; break;
        case '-': res = a - b; break;
        case '*': res = a * b; break;
        case '/': {
            if(b == 0) {
                cout << "ze";
                return 0;
            }
            res = a / b;
            break;
        }
    }

    cout << fixed << setprecision(3) << res;

    time();
    return 0;
}