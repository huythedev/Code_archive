#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	cin >> n;
	
	ll sumcs = 0, clcs = 0;
	while(n > 0) {
		sumcs += n % 10;
		clcs++;
		n /= 10;
	}
	
	cout << sumcs << endl << clcs;
	
    return 0;
}