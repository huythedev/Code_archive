#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string s1, s2; 
	getline(cin, s1);
	cin >> ws;
	getline(cin, s2);	
			
	cout << abs((int)s1.size() - (int)s2.size());
	return 0;
}
