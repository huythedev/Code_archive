#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string binary;
	cin >> binary;
	
	ll res = 0;
	for (ll i = 0; i < binary.length(); ++i) {
		res += (binary[i] - '0') * pow(2, binary.length() - 1 - i);
	}
	
	cout << res;

    return 0;
}