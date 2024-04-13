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

    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) cin >> a[i];

    int dainhat = INT_MIN;
    for(int i = 0; i < n - 1; ++i) {
        int j;
        for(j = i + 1; j < n; ++j)
            if(a[j] == a[j - 1] && a[j] == a[j + 1])
                break;
        if(i == 0)
            dainhat = max(dainhat, j - i);
        else
            dainhat = max(dainhat, j - i + 1);
    }

    cout << dainhat;

    return 0;
}
