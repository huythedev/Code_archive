#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long maxDifference(vector<long long> &buildings, int l, int r) {
    // Extract the subset of buildings from l to r
    vector<long long> subset;
    for (int i = l; i <= r; i++) {
        subset.push_back(buildings[i]);
    }
    
    // Sort the subset
    sort(subset.begin(), subset.end());
    
    // Arrange to maximize the difference in zigzag pattern
    vector<long long> arrangement;
    int left = 0, right = subset.size() - 1;
    bool fromLeft = true;
    
    while (left <= right) {
        if (fromLeft) {
            arrangement.push_back(subset[left++]);
        } else {
            arrangement.push_back(subset[right--]);
        }
        fromLeft = !fromLeft;
    }
    
    // Calculate the total difference
    long long totalDiff = 0;
    for (int i = 1; i < arrangement.size(); i++) {
        totalDiff += abs(arrangement[i] - arrangement[i - 1]);
    }
    
    return totalDiff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, Q;
    cin >> N >> Q;
    
    vector<long long> buildings(N + 1); // 1-indexed
    for (int i = 1; i <= N; i++) {
        cin >> buildings[i];
    }
    
    for (int q = 0; q < Q; q++) {
        int l, r;
        cin >> l >> r;
        cout << maxDifference(buildings, l, r) << endl;
    }
    
    return 0;
}
