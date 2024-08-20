#include <bits/stdc++.h>
using namespace std;

#define NAME "TASK2"

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	docfile();

	int A, B; cin >> A >> B;

	if(A % 2 == 0)
		++A;
	if(B % 2 == 0)
		--B;

	int nums = (B - A) / 2 + 1;

	cout << (A + B) * nums / 2;
	return 0;
}
