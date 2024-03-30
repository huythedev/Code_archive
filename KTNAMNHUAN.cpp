#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll A;
	cin >> A;
	
	if(A % 400 == 0) {
		cout << A << " " << 366;
	}
	else if(A % 4 == 0 && A % 100 != 0) {
		cout << A << " " << 366;
	}
	else {
		cout << A << " " << 365;
	}

    return 0;
}
