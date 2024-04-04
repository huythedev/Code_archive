#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, k;
    cin >> n >> k;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    while (k--) {
        int x;
        cin >> x;
        
        int l = 0, r = n;
        while (l < r) {
            int mid = l + (r - l) / 2;
            if (a[mid] < x) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        
        if (l == n) {
            cout << n + 1 << ln;
        } else {
            cout << l + 1 << ln;
        }
    }

    return 0;
}