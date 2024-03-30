#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
	freopen("SODEP.INP", "r", stdin);
	freopen("SODEP.OUT", "w", stdout);
}

bool checknto(ll x) {
	if (x == 2 || x == 3) {
		return true;
	}
	
	if (x <= 3 || x % 2 == 0 || x % 3 == 0) {
		return false;
	}
	
	for (ll i = 5; i * i < x; i += 6) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool checksodep(ll x) {
	ll t = 0;
	while(x > 0) {
		t += pow(x % 10, 2);
		x /= 10;
	}
	return checknto(t);
}

ll vitriso(ll x) {
	ll res = 0;
	long long t = 11;
	while (t < x) {
		if (checksodep(t)) {
			++res;
			++t;
		}
		else {
			++t;
		}
	}
	return res;
}

int main() {
	//docfile();
	ll N;
	cin >> N;
	
	bool res = checksodep(N);
	ll vitri = -1;
	if (res) {
		cout << "YES" << endl;
		cout << vitriso(N) + 1;
	}
	else {
		cout << "NO" << endl; 
		cout << vitri;
	}
	
    return 0;
}