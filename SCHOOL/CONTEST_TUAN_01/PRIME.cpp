#include <bits/stdc++.h>
using namespace std;

#define NAME "PRIME"
#define ln "\n"

typedef long long ll;
typedef long double ld;

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

void time() {
	cerr << ln << "Time elapsed: " << clock()/CLOCKS_PER_SEC << "s." << ln;
}

const int MAXN = 1000006;
int primes[MAXN];
vector<int> vec[MAXN];

void sieve() {
	for(int i = 2; i < MAXN; ++i) {
		if(primes[i] == 0) {
			primes[i] = i;
			for(int j = i * 2; j < MAXN; j += i) {
				if (primes[j] == 0) primes[j] = i;
			}
		}
	}
	for(int i = 2; i < MAXN; ++i) {
		int x = i;
		while(x > 1) {
			vec[i].push_back(primes[x]);
			x /= primes[x];
		}
	}
}

string convert_to_string(int n) {
    string res = "";
    if (n == 0) {
        res = "0"; 
    }
    while (n > 0) {
        res += char('0' + n % 10); 
        n /= 10;
    }
    reverse(res.begin(), res.end()); 
    return res; 
}


string get(int x) {
	set<int> tmp(vec[x].begin(), vec[x].end());
	string st = "";

	for (int f : tmp) {
		st += convert_to_string(f) + ",";
	}

	return st;
}

int solve(int a, int b) {
	unordered_map<string, int> hehe;
	int res = 0;

	for (int i = a; i <= b; ++i) {
		string st = get(i);
		res += hehe[st];
		hehe[st]++;
	}

	return res;
}

int main() {
	fastio();
	docfile();
	sieve();

	int tests;cin >> tests;
	while (tests--) {
		int a, b; cin >> a >> b;
		cout << solve(a, b) << "\n";
	}

	time();
    return 0;
}
