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

bool chia(vector<int> vec, int N, int max_keo) {
    int x = 0;
    for(int c : vec) {
        x += (c + max_keo - 1) / max_keo;
    }
    return x <= N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N, M; cin >> N >> M;
    vector<int> keo(M);
    for (int i = 0; i < M; i++) {
        cin >> keo[i];
    }

    int L = 1, R = accumulate(keo.begin(), keo.end(), 0LL);
    int res = R;
    while(L <= R) {
        int mid = (L + R) / 2;
        if(chia(keo, N, mid)) {
            res = mid;
            R = mid - 1;
        } 
        else {
            L = mid + 1;
        }
    }

    cout << res;

    return 0;
}