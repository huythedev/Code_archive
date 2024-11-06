#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // dp arrays to store the max sum if we keep or change the i-th element
    vector<ll> keep(n), change(n);

    // Base case for the first element
    keep[0] = 0; // No difference with a single element
    change[0] = abs(1 - a[0]); // Change first element to 1

    for (int i = 1; i < n; i++) {
        // Calculate max sum if keeping or changing the current element
        keep[i] = max(keep[i - 1] + abs(a[i] - a[i - 1]),
                      change[i - 1] + abs(a[i] - 1));
        
        change[i] = max(keep[i - 1] + abs(1 - a[i - 1]),
                        change[i - 1] + abs(1 - a[i - 1]));
    }

    // The answer is the maximum of keeping or changing the last element
    cout << max(keep[n - 1], change[n - 1]) << endl;

    return 0;
}
