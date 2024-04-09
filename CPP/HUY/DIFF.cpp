#include <bits/stdc++.h>
using namespace std;

#define NAME "DIFF"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int tim_M(int L, int R) {
    int mindiff = INT_MAX;
    int res = -1;

    for (int M = L; M < R; ++M) {
        int sum_left = 0, sum_right = 0;
        for (int i = L; i <= M; ++i)
            sum_left += i;
        for (int i = M + 1; i <= R; ++i)
            sum_right += i;

        int diff = abs(sum_left - sum_right);

        if (diff < mindiff) {
            mindiff = diff;
            res = M;
        }
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int L, R; cin >> L >> R;

    cout << tim_M(L, R);
    return 0;
}