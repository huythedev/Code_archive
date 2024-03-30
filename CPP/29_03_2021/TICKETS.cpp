#include <bits/stdc++.h>
#define NAME "TICKETS"
using namespace std;

typedef long long ll;

void docfile() {
	if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    ll n, k, p1, p2;
    cin >> n >> k >> p1 >> p2;

    ll res = 0;
    while(n >= k) {
        res += p2;
        n -= k;
    }   

    res += min(n * p1, p2);

    cout << res;

    return 0;
}