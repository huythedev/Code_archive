#include <bits/stdc++.h>
using namespace std;

bool is_special(int x) {
    int digit = x % 10;
    x /= 10;
    while (x > 0) {
        if (x % 10 != digit) return false;
        x /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    int count[1000001] = {0};
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (is_special(sum)) {
                count[sum]++;
            }
        }
    }
    
    long long ans = 0;
    for (int i = 0; i <= 1000000; i++) {
        ans += (long long)count[i] * (count[i] - 1) / 2;
    }
    cout << ans << endl;
    
    return 0;
}