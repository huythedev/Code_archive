// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "DQBN06"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

int main() {
    fastio();
    docfile();

    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n); // Pair to store value and original index
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1; // Store original index (1-based)
    }

    // DP table to store the maximum number of elements that can be selected with a given sum
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    vector<vector<bool>> take(n + 1, vector<bool>(k + 1, false));

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            // Do not take the current element
            dp[i][j] = dp[i - 1][j];
            // Take the current element if it does not exceed the sum
            if (j >= a[i - 1].first && dp[i - 1][j - a[i - 1].first] + 1 > dp[i][j]) {
                dp[i][j] = dp[i - 1][j - a[i - 1].first] + 1;
                take[i][j] = true;
            }
        }
    }

    // Find the maximum number of elements that can be selected
    int max_elements = 0, sum = 0;
    for (int j = 0; j <= k; ++j) {
        if (dp[n][j] > max_elements) {
            max_elements = dp[n][j];
            sum = j;
        }
    }

    // Reconstruct the solution
    vector<int> res;
    for (int i = n; i > 0; --i) {
        if (take[i][sum]) {
            res.push_back(a[i - 1].second); // Store original index
            sum -= a[i - 1].first;
        }
    }

    // Output the result
    cout << max_elements << ln;
    for (int i = res.size() - 1; i >= 0; --i) {
        cout << res[i] << " ";
    }
    cout << ln;

    time();
    return 0;
}