#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	cin >> ws;

	string s; getline(cin, s);

	string s2 = s;
	reverse(s2.begin(), s2.end());
	
	if(s == s2)
		cout << "TRUE";
	else
		cout << "FALSE";	

	return 0;
}
