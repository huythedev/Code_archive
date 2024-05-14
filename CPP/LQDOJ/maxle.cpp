#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int x) {
    int left = 0, right = arr.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] <= x) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    	int n, k;  cin >> n >> k;
    	vector<int> arr(n);
    	for (int i = 0; i < n; ++i)
        	cin >> arr[i];
    		
    	for (int i = 0; i < k; ++i) {
        	int x; cin >> x;

        	int res = binarySearch(arr, x);
        	if(res != -1) 
            		cout << res + 1 << endl;
        	else 
           		cout << 0 << endl;
    	}
    return 0;
}
