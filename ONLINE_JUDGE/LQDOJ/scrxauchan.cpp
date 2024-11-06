#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	string S; getline(cin, S);
	map<char, int> freq;
	for (char c : S)
		freq[c]++;

	bool allchan = true;
	for (auto &kv : freq)
		if (kv.second % 2 != 0)
			allchan = false;

	if (allchan)
		cout << "Yes";
	else
		cout << "No";

	return 0;
}