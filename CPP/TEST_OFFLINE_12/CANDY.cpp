#include <bits/stdc++.h>
using namespace std;

#define NAME "CANDY"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool can_eat(ll n, ll k) {
    ll total = 0;
    ll conlai = n;
    
    while (conlai > 0) {
        ll tmp = min(k, conlai);
        total += tmp;
        conlai -= tmp;
        
        ll tmp2 = conlai / 10;
        conlai -= tmp2;
    }
    
    return total * 2 >= n;
}

ll xuly(ll n) {
    ll l = 1, r = n;
    
    while(l < r) {
        ll mid = (l + r) / 2;
        if(can_eat(n, mid))
            r = mid;
        else 
            l = mid + 1;
    }
    
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    ll n;
    cin >> n;
    
    cout << xuly(n);
    
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
    return 0;
}
