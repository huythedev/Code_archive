#include <bits/stdc++.h>
using namespace std;

#define NAME "SUMSOCP"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isCP(int n) {
    return (int)sqrt(n) * (int)sqrt(n) == n;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N; cin >> N;
    vector<int> a(N);
    for(int &x : a) {
        cin >> x;
    }

    sort(a.begin(), a.end());
    ll res = 0;
    for(int i = 0; i < N - 1; ++i) {
        if(a[i + 1] != a[i] + 1) {
            for(int j = a[i]; j <= a[i + 1]; ++j) {
                if(isCP(j)) 
                    res += j;
            }
        }
    }

    cout << res;
    
    return 0;
}