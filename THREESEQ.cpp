#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	ll N, M;
	cin >> N >> M;
	
	ll sonhom = N / 3;
	if(N % 3 != 0) {
		++sonhom;
	}

	ll sl1, sl2, sl3;
	if(N % 3 == 0) {
		sl1 = sl2 = sl3 = N / 3;
	}
	else if(N % 3 == 1) {
		sl2 = sl3 = N / 3;
		sl1 = N / 3 + 1;
	}
	else {
		sl1 = sl2 = N / 3 + 1;
		sl3 = N / 3;
	}
	
	if(M > sl1 + sl2) {
		cout << 3 * (M - sl1 - sl2);
	}
	else if(M > sl1) {
		cout << 2 + 3 * (M - sl1 - 1);
	}
	else {
		cout << 1 + 3 * (M - 1);
	}

    return 0;
}
