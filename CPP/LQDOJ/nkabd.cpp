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

ll sumdiv[1000000 + 5];

void pre_calc() {
    for (int i = 1; i <= 1e6; ++i)
        for (int j = i; j <= 1e6; j += i)
            sumdiv[j] += i;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int L, R; cin >> L >> R;

    int res = 0;
    for(int i = L; i <= R; ++i)
        if(sumdiv[i] - i > i)
            ++res;

    cout << res;

    return 0;
}