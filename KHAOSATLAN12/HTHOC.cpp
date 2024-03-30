#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	ll k;
	
	cin >> k;
	
	if (k == 1) {
		cout << "7 45";
	}
	else if (k == 2) {
		cout << "8 40";
	}
	else if (k == 3) {
		cout << "9 30";
	}
	else if (k == 4) {
		cout << "10 25";
	}
	else if (k == 5) {
		cout << "11 15";
	}
    return 0;
}