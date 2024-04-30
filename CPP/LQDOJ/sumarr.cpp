#include <bits/stdc++.h>
using namespace std;

#define NAME "sumarr"
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
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
		cout << A[i] + B[i] << " ";
	}

	return 0;
}