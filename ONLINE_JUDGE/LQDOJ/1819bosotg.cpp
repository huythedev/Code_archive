#include <bits/stdc++.h>
using namespace std;

#define NAME "BSTG"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME ".inp")) {
        freopen(NAME ".inp", "r", stdin);
        freopen(NAME ".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n;
    cin >> n;
    vector<ll> vec(n);
    for (ll i = 0; i < n; ++i) {
        cin >> vec[i];
    }

    sort(vec.begin(), vec.end());
    ll res = 0;
    for(ll i = n - 1; i >= 2; --i) {
        ll left = 0, right = i - 1;
        while(left < right) {
            if(vec[left] + vec[right] > vec[i]) {
                res += right - left;
                --right;
            } 
			else {
                ++left;
            }
        }
    }
    cout << res;
    return 0;
}
