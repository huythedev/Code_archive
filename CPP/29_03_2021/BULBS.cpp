#include <bits/stdc++.h>
#define NAME "BULBS"
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
	
	if(n % 2 == 0) {
		cout << "OFF";
	}
	else {
		cout << "ON";
	}

    return 0;
}