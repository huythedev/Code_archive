#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	string A, B; cin >> A >> B;

	for(int i = 0; i < A.size(); ++i) {
		string tmp = A.substr(i, B.size());

		if(tmp == B)
			cout << i + 1 << ' ';
	}	
	return 0;
}
