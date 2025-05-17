// Author: huythedev
// Problem Link: https://vjudge.net/contest/714979#problem/E
#include <bits/stdc++.h>
using namespace std;

#define NAME "E"
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

double a, b, c, d;

double func(double x) {
    return a * x * x * x + b * x * x + c * x + d;
}

signed main() {
    fastio();
    docfile();

    cin >> a >> b >> c >> d;

    vector<double> vec;
    for (int i = -10000; i <= 10000; ++i) {
        if (vec.size() == 3) {
            break;
        }

        double x = (double)i / 100.0;
        
        if (fabs(func(x)) < 1e-5) {
            vec.push_back(x);
            i += 99; 
        }
    }

    cout << fixed << setprecision(2);
    for (int j = 0; j < vec.size(); ++j) {
        cout << vec[j] << (j == vec.size() - 1 ? "" : " ");
    }

    time();
    return 0;
}