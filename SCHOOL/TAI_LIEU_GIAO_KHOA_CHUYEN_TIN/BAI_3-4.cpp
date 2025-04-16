// Author: huythedev (https://huythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI_3-4"
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

    int n; ll k; cin >> n >> k;
    string num = "";
    for(int i = 1; i <= n; ++i) num += to_string(i);

    if(k >= num.sz) {
        cout << -1;
        return 0;
    }

    for(ll i = 0; i < k; ++i) {
        for(int j = 0; j < num.sz - 1; ++j) {
            if(num[j] < num[j + 1]) {
                num.erase(j, 1);
                break;
            }
        }
    }

    cout << num;

    time();
    return 0;
}