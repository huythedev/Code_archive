#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int q; cin >> q;

	while(q--) {
		int n; cin >> n;

		n %= 5;
		if(n == 1)
			cout << "Butter Bread";
		else if(n == 2)
			cout << "Night City";
		else if(n == 3)
			cout << "Panda";
		else if(n == 4)
			cout << "Urban Life";
		else
			cout << "Water Life";
		cout << endl;
	}
	return 0;
}	
