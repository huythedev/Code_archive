#include <bits/stdc++.h>
using namespace std;

#define NAME "divisorofn01"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int cntdiv(int n) {
	int res = 0;
	for(int i = 1; i * i <= n; ++i) {
		if(n % i == 0) {
			++res;
			if(n / i != i)
				++res;
		}
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    int n; cin >> n;

    cout << cntdiv(n);

    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
    return 0;
}
