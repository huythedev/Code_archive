#include <bits/stdc++.h>
using namespace std;

#define NAME "querysum2"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

const int MAX_N = 100005;

vector<ll> arr(MAX_N);
vector<ll> tree(4 * MAX_N);

void build(int node, int start, int end) {
	if (start == end) {
		tree[node] = arr[start];
		return;
	}

	int mid = (start + end) / 2;
	build(2 * node, start, mid);
	build(2 * node + 1, mid + 1, end);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

void update(int node, int start, int end, int left, int right, ll val) {
	if (end < left || start > right) {
		return;
	}

	if (start == end) {
		tree[node] += val;
		return;
	}

	int mid = (start + end) / 2;
	update(2 * node, start, mid, left, right, val);
	update(2 * node + 1, mid + 1, end, left, right, val);
	tree[node] = tree[2 * node] + tree[2 * node + 1];
}

ll query(int node, int start, int end, int left, int right) {
	if (end < left || start > right) {
		return 0;
	}

	if (left <= start && end <= right) {
		return tree[node];
	}

	int mid = (start + end) / 2;
	ll leftSum = query(2 * node, start, mid, left, right);
	ll rightSum = query(2 * node + 1, mid + 1, end, left, right);
	return leftSum + rightSum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n, q; cin >> n >> q;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];


	build(1, 1, n);

	for (int i = 0; i < q; i++) {
		int op, u, v;
		ll x;
		cin >> op;

		if (op == 1) {
			cin >> u >> v >> x;
			update(1, 1, n, u, v, x);
		}
		else {
			cin >> u >> v;
			cout << query(1, 1, n, u, v) << ln;
		}
	}

	return 0;
}