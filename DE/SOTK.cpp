#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void docfile() {
	freopen("SOTK.inp", "r", stdin);
	freopen("SOTK.out", "w", stdout);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	docfile();
	string s;
	getline(cin, s);
	ll k;
	cin >> k;
	
	set <char> tmp (s.begin(), s.end());
	
	vector <ll> arr;
	for (char c : tmp) {
		arr.push_back(c - '0');
	}
	
	sort(arr.rbegin(), arr.rend());
	cout << arr[k - 1];
    return 0;
}