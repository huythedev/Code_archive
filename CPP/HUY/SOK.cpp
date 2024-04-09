#include <bits/stdc++.h>
using namespace std;

#define NAME "SOK"
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

    int n, k; cin >> n >> k;
    vector<ll> A(n);
    for(int i = 0; i < n; ++i)
        cin >> A[i];

    sort(A.rbegin(), A.rend());
    for (int i = 0; i < A.size() - 1; ++i) {
        while (i < A.size() - 1 && A[i + 1] == A[i]) {
            A.erase(A.begin() + i + 1);
        }
    }
    
    cout << A[k - 1];

    return 0;
}