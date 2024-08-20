#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
  ll n;
  cin >> n;
  
  vector<int> heights(n);
  for(ll i = 0; i < n; ++i) {
    cin >> heights[i];
  }
  
  vector<vector<int> > dp(n, vector<int>(n));
  for(int i = 0; i < n - 1; ++i) {
    for(int j = i+1; j < n; ++j) {
      if(heights[i] > heights[j]) {
        dp[i][j] = heights[j]; 
      }
      else {
        dp[i][j] = dp[i][j-1];
      }
    }
  }
  
  int ans = INT_MAX;
  for(int i = 0; i < n; ++i) {
    ans = min(ans, dp[0][i] + accumulate(heights.begin() + i + 1, heights.end(), 0));
  }
  
  cout << ans << endl;
  
  return 0;
}