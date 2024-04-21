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

bool compare(pair<int, int> &i, pair<int, int> &j) {
    return i.first < j.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;
    pair<int, int> arr[n];

    for (int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        arr[i] = {a, b};
    }

    sort(arr, arr + n, compare);
    for (auto &kv : arr) {
        cout << kv.first << ' ' << kv.second << ln;
    }

    return 0;
}