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

const int MAX_N = 3005;
int f[MAX_N], g[MAX_N];
int c, Q;

bool canWin(int idx, bool isMax) {
    bool res = false;
    for (int i = 0; i < f[idx]; i++) {
        for (int j = 0; j <= g[idx]; j++) {
            if (i + j > 0) {
                int newf = f[idx] - i;
                int newg = g[idx] - j + max(0, c * i);
                bool nextMove = canWin(idx, !isMax);
                if (isMax) {
                    res = res || !nextMove;
                } else {
                    res = res || nextMove;
                }
                f[idx] = newf;
                g[idx] = newg;
            }
        }
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    cin >> c >> Q;
    for (int i = 0; i < Q; i++) {
        cin >> f[i] >> g[i];
    }

    for (int i = 0; i < Q; i++) {
        if (canWin(i, true)) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }

    return 0;
}