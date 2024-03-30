#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
    freopen("SUMSOCP.inp", "r", stdin);
    freopen("SUMSOCP.out", "w", stdout);
}

bool checkcp(ll n) {
    if (sqrt(n) == (ll)sqrt(n)) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    ll n;
    cin >> n;
    vector <ll> a;
    while (n--) {
        ll x;
        cin >> x;
        a.push_back(x);
    }

    ll res = 0;
    for (ll i = 0; i <= 1e9; i++) {
        //If i doesn't in a, then continue
        if (find(a.begin(), a.end(), i) == a.end()) continue;
    }
    return 0;
}