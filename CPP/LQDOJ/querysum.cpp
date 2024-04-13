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

<<<<<<< Updated upstream
    int n, q;
    cin >> n >> q;
    vector<ll> a(n + 1);
    vector<ll> f(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (q--) {
        int L, R;
        ll V;
        cin >> L >> R >> V;
        f[L] += V;
        if (R + 1 <= n) {
            f[R + 1] -= V;
        }
    }

    for (int i = 1; i <= n; i++) {
        f[i] += f[i - 1];
    }

    for (int i = 1; i <= n; i++) {
        cout << a[i] + f[i] << " ";
    }


=======
    int N, Q; cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; ++i)
        cin >> A[i];

    while(Q--) {
        int type; cin >> type;

        if(type == 1) {
            int p, x; cin >> p >> x;
            A[p - 1] += x;
        }
        else {
            int l, r; cin >> l >> r;
            l--; r--;

            ll sum = 0;
            for(int i = l; i <= r; ++i)
                sum += A[i];
            cout << sum << ln;
        }
    }

>>>>>>> Stashed changes
    return 0;
}