// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "CPERMPRI"
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

    int array[] = {0, 1, 1, 3, 48, 60, 3240, 10080, 725760};
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        cout << array[n] << ln;
    }

    time();
    return 0;
}