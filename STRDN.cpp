#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define NAME "NAME"

const ll MAXN = 2e5 + 5;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);

    string s;
    cin >> s;
    
    ll q;
    cin >> q;

    ll n = s.length();
    s = " " + s;
    ll tmp = (n + 1) / 2;

    vector<ll> vec(MAXN, 0);
    while(q--) {
        ll x;
        cin >> x;

        if (x >= tmp) 
            x = n - x + 1;

        vec[tmp + 1]--;
        vec[x]++;
    }  

    for (ll i = 1; i <= n; ++i) 
        vec[i] += vec[i - 1];

    for (ll i = 1;i <= tmp; ++i) {
        if (vec[i] % 2 != 0) 
            swap(s[i], s[n - i + 1]);
    }
    s.erase(0,1);
    cout << s;

    return 0;
}