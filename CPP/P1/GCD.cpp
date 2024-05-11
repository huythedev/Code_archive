#include <bits/stdc++.h>
using namespace std;

#define NAME "GCD"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    int N; cin >> N;
    N--;

   	int t; cin >> t;
   	int res = t;
   	while(N--) {
   		cin >> t;
   		res = __gcd(t, res);
   	}

   	cout << res;

    return 0;
}
