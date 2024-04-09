#include <bits/stdc++.h>
using namespace std;

#define NAME "NMIN"
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

    set<int> A;
    for(int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        A.insert(x);
    }

    int i = 0;
    for(int x : A) {
        if(x != i) {
            cout << i;
            return 0;
        }
        ++i;
    }

    cout << i;
    
    return 0;
}