#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

long long countP (long long a, long long b) {
	string st = "";
	for (long long i = a; i <= b; ++i) {
		long long t = pow(i, 2);
		string s = to_string(t);
		st += s;
	}
	return st.length();
}

int main() {
	long long x, y;
	cin >> x >> y;
	long long res = countP(x, y);
	cout << res;

    return 0;
}