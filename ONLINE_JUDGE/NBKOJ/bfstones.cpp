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

    int N, Q;
    cin >> N >> Q;
    vector<int> w(N);
    for (int i = 0; i < N; ++i) {
        cin >> w[i];
    }
    sort(w.begin(), w.end());

    while (Q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;

        int second_max = -1;
        for (int i = r; i >= l; i--) {
            if (w[i] < second_max) {
                second_max = w[i];
                break;
            }
        }

        int pos = upper_bound(w.begin(), w.end(), second_max) - w.begin();
        cout << pos << '\n';
    }

    return 0;
}