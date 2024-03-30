#include <bits/stdc++.h>
#define NAME "NTFS"
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
	
	ll n;
	cin >> n;
	
	if(n % 4096 == 0) {
		cout << (n / 4096) * 4;
	}
	else {
		cout << ((ll)n / 4096 + 1) * 4;
	}

    return 0;
}