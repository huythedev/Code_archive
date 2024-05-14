#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string N; cin >> N;
	bool AllDigit = true;
	for(char c : N) {
		int tmp = c - '0';
		if(tmp < 0 || tmp > 9) {
			AllDigit = false;
			break;
		}
	}

	if(!AllDigit || N[0] == '0')
		cout << -1;
	else {
		char c = N[N.size() - 1];
		N.erase(N.size() - 1, 1);

		if(c == '0') {
			char c2 = N[N.size() - 1];
			N.erase(N.size() - 1, 1);

			cout << N << c2 - '0' - 1 << 9;
		}	
		else 
			cout << N << c - '0' - 1;
	}

	return 0;
}
