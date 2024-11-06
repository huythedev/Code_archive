#include <bits/stdc++.h>
using namespace std;

#define NAME "sinhhv"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool solve(vector<int>& nums) {
	int n = nums.size();
	int i = n - 2;
	while (i >= 0 && nums[i] >= nums[i + 1]) {
		i--;
	}
	if (i < 0) return false;
	int j = n - 1;
	while (nums[j] <= nums[i]) {
		j--;
	}
	swap(nums[i], nums[j]);
	reverse(nums.begin() + i + 1, nums.end());
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int n; cin >> n;

	vector<int> nums(n);
	for (int i = 0; i < n; ++i) {
		nums[i] = i + 1;
	}

	sort(nums.begin(), nums.end());

	do {
		for (int i : nums)
			cout << i;
		cout << ln;
	} while (solve(nums));

	return 0;
}
