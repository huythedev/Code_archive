#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 5;

ll bit[MAXN],a[MAXN];

void update(ll x, ll v) {
	for (; x < MAXN; x += x & -x) 
		bit[x] += v;
}

ll get(ll x) {
	ll res = 0;
	for (; x; x -= x & -x)
	       	res += bit[x];
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;

    for(ll i = 1;i <= n;i++) {
    	cin >> a[i];
    	update(i, a[i]);
    }

    while(q--) {
    	ll type, l, r; cin >> type >> l >> r;

    	if (type == 1) {
    		update(l, r - a[l]);
    		a[l] = r;
    	} 
	else {
    		cout << get(r) - get(l - 1) << '\n';
    	}
    }


    cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
    return 0;
}

