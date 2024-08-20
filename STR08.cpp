#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll n;
	cin >> n;
	
	string st;
	while(n--) {
		cin >> st;
		string t = st;
		reverse(st.begin(), st.end());
		if(st == t) {
			cout << 1;
		}
		else {
			cout << 0;
		}
	}

    return 0;
}