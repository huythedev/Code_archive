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

    int n; ll c; cin >> n >> c;
    pair<int, int> arr[n];
    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr + n);
    int res = 0;
    for(int i = 0; i < n; ++i) {
        if(c >= arr[i].first) {
            c += arr[i].second;
            ++res;
        }
        else 
            break;
    }

    cout << res;

    return 0;
}