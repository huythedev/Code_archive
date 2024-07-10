#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const int MAXN = 1e7 + 5;
bool prime[MAXN];

void sieve() {
	fill(prime, prime + MAXN, true);
	prime[0] = prime[1] = false;
	for(int i = 2; i < MAXN; ++i) {
		if(prime[i])
			for(int j = i * 2; j < MAXN; j += i)
				prime[j] = false;
	}
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(NULL); cout.tie(NULL);
    	docfile();

    	sieve();

	int A, B; cin >> A >> B;

	for(int i = A; i <= B; ++i)
		if(prime[i])
			cout << i << endl;

    	return 0;
}
