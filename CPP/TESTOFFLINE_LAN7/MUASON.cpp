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

    int N; cin >> N;

    set<int> a;
    for(int i = 0; i < N; i++) {
        int t; cin >> t;
        a.insert(t);
    }
    
    cout << (ll)pow(2, N) - 1 - (N - a.size());

    return 0;
}
