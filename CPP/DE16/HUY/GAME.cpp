#include <bits/stdc++.h>
using namespace std;

#define NAME "GAME"

void fastio() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

int main() {
	fastio();
	docfile();

	int N; cin >> N;
	
	int tmp = 1;
	while(pow(2, tmp) <= N) 
		++tmp;
	
	--tmp;

	cout << 2 * (N - (int)pow(2, tmp)) + 1;
	return 0;
}
