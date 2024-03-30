#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll p, q, r, s, u, v;
	cin >> p >> q >> r >> s >> u >> v;
	
	ll A = 0, B = 0, C = 0;
	
	if(p > q) {
		A += 3;
	}
	else if(p < q) {
		B += 3;
	}
	else {
		A++;
		B++;
	}
	
	if(r > s) {
		A += 3;
	}
	else if(r < s) {
		C += 3;
	}
	else {
		A++;
		C++;
	}
	
	if(u > v) {
		B += 3;
	}
	else if(u < v) {
		C += 3;
	}
	else {
		B++;
		C++;
	}
	
	cout << A << " " << B << " " << C;

    return 0;
}