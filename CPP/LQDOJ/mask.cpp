#include <bits/stdc++.h>
using namespace std;

#define NAME "mask"
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

	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	sort(A.begin(), A.end());

	int Q; cin >> Q;
	while (Q--) {
		int M; cin >> M;

		auto it = lower_bound(A.begin(), A.end(), M);

		int res = it - A.begin();

		cout << res << ln;
	}

	return 0;
}