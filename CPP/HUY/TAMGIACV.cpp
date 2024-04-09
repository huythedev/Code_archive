#include <bits/stdc++.h>
using namespace std;

#define NAME "TAMGIACV"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isPytago(int a, int b, int c) {
    if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N; cin >> N;
    vector<ll> A(N);
    for(ll &x : A) cin >> x;

    for(int i = 0; i < N - 2; ++i) {
        if(isPytago(A[i], A[i + 1], A[i + 2]))
            cout << A[i] << " " << A[i + 1] << " " << A[i + 2] << ln;
    }

    return 0;
}