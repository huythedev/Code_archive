#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> stones(n);
    for (int i = 0; i < n; i++) {
        cin >> stones[i];
    }
    
    // Create a single array with 2n elements to handle the circular nature
    vector<pair<int, int>> indexed_stones(2*n);
    for (int i = 0; i < 2*n; i++) {
        indexed_stones[i] = {stones[i % n], i};
    }
    
    vector<int> dp;  // Will store the LIS
    vector<int> lis_len(2*n, 0);  // Length of LIS ending at each position
    int max_len = 0;
    
    for (int i = 0; i < 2*n; i++) {
        // Only consider elements that could form part of a sequence of length <= n
        if (i >= n && indexed_stones[i].second - n >= 0) {
            // Remove elements from dp that are out of the sliding window
            while (!dp.empty() && indexed_stones[dp[0]].second <= indexed_stones[i].second - n) {
                dp.erase(dp.begin());
            }
        }
        
        // Find the position to insert the current element using binary search
        auto it = lower_bound(dp.begin(), dp.end(), i, 
                             [&](int a, int b) {
                                 return indexed_stones[a].first < indexed_stones[b].first;
                             });
        
        if (it == dp.end()) {
            dp.push_back(i);
        } else {
            *it = i;
        }
        
        lis_len[i] = dp.size();
        
        // Update max length for sequences within length n
        if (i < n || (indexed_stones[i].second - indexed_stones[i-n+1].second) < n) {
            max_len = max(max_len, lis_len[i]);
        }
    }
    
    cout << n - max_len << endl;
    return 0;
}
