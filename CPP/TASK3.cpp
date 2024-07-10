#include <bits/stdc++.h>
using namespace std;

#define NAME "TASK3"

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	docfile();

	int A, B; cin >> A >> B;

	int nums = (B - A) + 1;

	cout << (A + B) * nums / 2;

	return 0;
}
