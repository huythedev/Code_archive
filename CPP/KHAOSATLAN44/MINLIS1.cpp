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

    int N;
    cin >> N;

    vector<int> a(N);
    for(int i = 0; i < N; ++i)
        cin >> a[i];

    int res = INT_MAX;
    for(int i = 0; i < N - 1; ++i) {
        int tmp = 0;
        for(int j = i + 1; j < N; ++j) {
            if(a[j] < a[j - 1])
                tmp++;
        }
        res = min(res, tmp);
    }

    cout << res;

    return 0;
}