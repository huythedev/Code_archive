#include <bits/stdc++.h>
using namespace std;

#define NAME "matong"
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
    vector<int> A(N);
    for (int i = 0; i < N; ++i)
        cin >> A[i];

    ll res = 0;
    for (int i = 0; i < N; ++i) {
        int divi = 0;
        for (int j = 1; j * j <= A[i]; ++j) {
            if (A[i] % j == 0) {
                if (A[i] / j == j)
                    ++divi;
                else
                    divi += 2;
            }
        }
        res += A[i] * divi;
    }

    cout << res;

    return 0;
}