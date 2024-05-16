#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string B, A; cin >> B >> A;

	int res = 0;
	for(int i = 0; i < B.size(); ++i) {
		string tmp = B.substr(i, A.size());

		if(tmp == A)
			++res;
	}
	cout << res;
	return 0;
}
