#include <bits/stdc++.h>
using namespace std;

#define NAME "sodep"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}

void docfile() {
	if (ifstream(NAME ".INP")) {
		freopen(NAME ".INP", "r", stdin);
		freopen(NAME ".OUT", "w", stdout);
	}
}

void time() {
	cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
		 << ln;
}

bool is_beauty(string n) {
	int sum = 0;
	for (int i = 0; i < n.sz; i++) {
		sum += n[i] - '0';
	}
	return sum % 5 == 0;
}

int main() {
	fastio();
	docfile();

	int n; cin >> n;
	while(n--) {
		string s; cin >> s;
		if(is_beauty(s)) cout << s << ' ';
	}

	time();
	return 0;
}