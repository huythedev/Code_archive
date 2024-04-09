#include <bits/stdc++.h>
using namespace std;

#define NAME "MAXVT"
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

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int vt, dodai = INT_MIN;
    for(int i = 0; i < n; ++i) {
        int tmp = 1;
        while(a[i + tmp] > a[i + tmp - 1]) {
            ++tmp;
        }

        if(dodai < tmp) {
            dodai = tmp;
            vt = i;
        }

        i += tmp - 1;
    }

    cout << vt + 1 << " " << dodai;

    return 0;
}
