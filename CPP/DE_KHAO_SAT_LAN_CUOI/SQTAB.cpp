#include <bits/stdc++.h>
using namespace std;

#define NAME "SQTAB"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n, k; cin >> n >> k;
    vector<ll> vec;
    for(ll i = 1; i <= n; ++i) {
        vec.push_back(2 * i * i);
        for(int j = i + 1; j <= n; ++j) {
            vec.push_back(i * i + j * j);
            vec.push_back(i * i + j * j);
        }
    }

    sort(vec.begin(), vec.end());

    cout << vec[k - 1];
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s";
    return 0;
}
