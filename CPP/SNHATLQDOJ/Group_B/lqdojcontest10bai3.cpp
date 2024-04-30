#include <bits/stdc++.h>
using namespace std;

#define NAME "lqdojcontest10bai3"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N; cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i)
        cin >> a[i];

    reverse(a.begin(), a.end());

    int res = 0;

    for (int i = 1; i < N; ++i) {
        if (a[i] > a[i - 1]) {
            res++;
            a[i] = a[i - 1];
        }
    }

    cout << res;

    return 0;
}