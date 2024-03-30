#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll t;
	cin >> t;
	vector <string> res; 
	while (t--) {
		string str1;
		cin >> str1;
		string tmp = "";
		
		for (char c : str1) {
			if (c == 'u' || c == 'e' || c == 'o' || c == 'a' || c == 'i' || c == 'U' || c == 'E' || c == 'O' || c == 'A' || c == 'I') {
				char ct = toupper(c);
				tmp += (char)ct;
			}
			else {
				char ct = tolower(c);
				tmp += (char)ct;
			}
		}
		res.push_back(tmp);
	}
	q
	for (string st : res) {
		cout << st << endl;
	}

    return 0;
}