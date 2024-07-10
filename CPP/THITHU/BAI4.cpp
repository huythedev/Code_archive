#include <bits/stdc++.h>
using namespace std;

#define NAME "BAI4"

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

bool isCP(int n) {
	int sqrt_n = (int)sqrt(n);
	return sqrt_n * sqrt_n == n && n > 3;
}

int main() {
	fastio();
	docfile();

	int n; cin >> n;

	vector<int> vec(n);
	for(int i = 0; i < n; ++i)
		cin >> vec[i];

	int res = 0;
	for(int i = 0; i < n - 1; ++i) {
		int tmp = 0;
		for(int j = i + 1; j < n && abs(j - 1) <= 10; ++j) {
			//cout << abs(vec[j] - vec[i]) << endl;

			if(isCP(abs(vec[j] - vec[i])))
				++tmp;
		}	
		res = max(tmp, res);
	}	

	cout << res;

	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}

