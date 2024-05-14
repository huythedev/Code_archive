#include <bits/stdc++.h>
using namespace std;

int sumdigit(string s) {
	int res = 0;
	for(char c : s)
		res += c - '0';
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t; cin >> t;
	while(t--) {
		string s; cin >> s;

		cout << sumdigit(s) << endl;
	}
	return 0;
}
