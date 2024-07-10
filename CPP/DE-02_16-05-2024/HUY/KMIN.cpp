#include <bits/stdc++.h>
using namespace std;

#define NAME "KMIN"

void docfile() {
	if(ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	int N; cin >> N;

	int arr[N];
	for(int i = 0; i < N; ++i)
		cin >> arr[i];

	sort(arr, arr + N);
	
	bool found = false;
	if(arr[0] != 0) {
		cout << 0;
		found = true;
	}
	else {
		for(int i = 0; i < N - 1; ++i) {
			if(arr[i] + 1 != arr[i + 1]) {
				cout << arr[i] + 1;
				found = true;
				break;	
			}
		}
	}

	if(!found)
		cout << arr[N - 1] + 1;
	return 0;
}
