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

    int N, X; cin >> N >> X;

    vector<int> A(N);
    for(int i = 0; i < N; ++i) 
        cin >> A[i];

    for(int l = 1, r = N - 1; l < r; ++l)
    {
        while(l < r - 1 && A[l] + A[r] > X) 
            r--;

        if(A[l] + A[r] == X)
        {
            cout << l + 1 << " " << r + 1;
            return 0;
        }
    }

    cout << "No solution";

    return 0;
}