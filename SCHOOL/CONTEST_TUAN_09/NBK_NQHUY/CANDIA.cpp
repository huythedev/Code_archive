// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "CANDIA"
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

signed main() {
    fastio();
    docfile();

    ll n; cin >> n;
    vector<ll> vec1, vec2;
    ll power = 1;
    
    while (n > 0) {
        ll tmp = n % 3;
        if (tmp == 1) {
            vec1.push_back(power);
            n--;
        }
        else if (tmp == 2) {
            vec2.push_back(power);
            ++n;
        }
        n /= 3;
        power *= 3;
    }

    sort(vec1.begin(), vec1.end());
    sort(vec2.begin(), vec2.end());

    for (ll i = 0; i < vec1.size(); i++) 
        cout << vec1[i] << (i < vec1.size() - 1 ? " " : "");
    cout << ln;
    for (ll i = 0; i < vec2.size(); i++) 
        cout << vec2[i] << (i < vec2.size() - 1 ? " " : "");
    cout << ln;

    time();
    return 0;
}