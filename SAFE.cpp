#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N;
	string st;
	cin >> N;
	cin >> st;
	
	set<char> diff;
	bool lienke = false;
	for(ll i = 0; i < st.length(); ++i) {
		if(st[i] == st[i + 1]) {
			lienke = true;
		}
		diff.insert(st[i]);
	}
	
	if(diff.size() < 5) {
		cout << "0";
	}
	else if(lienke && diff.size() >= 5) {
		cout << "0";
	}
	else {
		cout << "1";
	}

    return 0;
}