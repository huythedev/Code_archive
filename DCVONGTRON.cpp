#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string decrypt(string st) {
	string res = "";
	for (long long i = 0; i < st.size(); i += 2) {
		char c = st[i];
		long long t1 = st[i + 1] - '0';
		long long t = c + t1;
		if (t > 90) {
			t = 65 + (t - 90 - 1);
		}
		char c1 = t;
		res += c1;
	}
	return res;
}

int main() {
	string st;
	getline(cin, st);
	string res = decrypt(st);
	cout << res;
	
    return 0;
}