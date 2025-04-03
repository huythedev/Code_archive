#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const string str = "100000000000000000"; // Input number as string
const ll target = 10; // Target sum
unordered_map<int, unordered_map<ll, ll>> dp; // Memoization: dp[pos][sum]

ll count_ways(int pos, ll current_sum) {
    if (pos == str.size()) {
        return current_sum == target ? 1 : 0;
    }
    // Check memoization
    if (dp.count(pos) && dp[pos].count(current_sum)) {
        return dp[pos][current_sum];
    }
    ll count = 0;
    ll num = 0;
    // Build number from current position
    for (int i = pos; i < str.size(); i++) {
        num = num * 10 + (str[i] - '0');
        if (pos == 0) {
            // First number has no sign before it
            count += count_ways(i + 1, num);
        } else {
            // Try adding or subtracting the number
            count += count_ways(i + 1, current_sum + num);
            count += count_ways(i + 1, current_sum - num);
        }
    }
    return dp[pos][current_sum] = count;
}

int main() {
    ll result = count_ways(0, 0);
    cout << result << endl;
    return 0;
}