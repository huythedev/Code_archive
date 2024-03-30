#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  cin >> n >> k;
  
  vector<int> b(n);
  for(int i = 0; i < n; i++) {
    cin >> b[i]; 
  }
  
  vector<int> f(n, 0);
  f[0] = b[0];
  
  for(int i = 1; i < n; i++) {
    f[i] = b[i];
    for(int j = max(0, i - k); j < i; j++) {
      if(i - j == b[i] - b[j]) {
        f[i] = max(f[i], f[j] + b[i]);  
      }
    }
  }

  cout << f[n-1] << endl;
  
  return 0;
}