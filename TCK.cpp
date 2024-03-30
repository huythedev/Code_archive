#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	string st;
	getline(cin, st);
	
	for(ll i = 1; i <= st.length(); ++i) {
		string tmp = "", t = st.substr(0, i);
		while(tmp.length() < st.length()) {
			tmp += t;
		}
		if(tmp.substr(0, st.length()) == st) {
			cout << i << " ";
		}
	}
	
    return 0;
}