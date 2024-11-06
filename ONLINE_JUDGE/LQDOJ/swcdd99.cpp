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

    int N;
    cin >> N;

    vector<int> A;
    int k = 9;
    while (k != 0) {
        A.push_back(N / k);
        N = N % k;
        k--;
    }
    
    reverse(A.begin(), A.end());
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != 0) {
            cout << string(A[i], char('0' + i + 1));
        }
    }

    return 0;
}