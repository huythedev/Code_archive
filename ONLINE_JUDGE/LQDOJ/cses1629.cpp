#include <bits/stdc++.h>
using namespace std;

#define NAME "cses1629"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool sosanh(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n;
	cin >> n;

	vector<pair<int, int>> time(n);
	for (int i = 0; i < n; i++)
		cin >> time[i].first >> time[i].second;


	sort(time.begin(), time.end(), sosanh);

	int res = 1;
	int ketthuc = time[0].second;

	for (int i = 1; i < n; i++) {
		if (time[i].first >= ketthuc) {
			res++;
			ketthuc = time[i].second;
		}
	}

	cout << res;

	return 0;
}