#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b = a;
    b.insert(b.end(), a.begin(), a.end());
    int max_lis = 0;
    set<int> s;
    for (int i = 0; i < n; i++) {
        auto it = s.lower_bound(b[i + n - 1]);
        if (it != s.begin()) {
            it--;
            s.erase(it);
        }
        s.insert(b[i + n - 1]);
        if (i > 0) {
            auto it2 = s.find(b[i - 1]);
            if (it2 != s.end()) s.erase(it2);
        }
        max_lis = max(max_lis, (int)s.size());
    }
    cout << n - max_lis << endl;
    return 0;
}