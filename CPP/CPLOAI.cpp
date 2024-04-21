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
    set<int> s;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        s.insert(x);
    }

    cout << s.size() << ln;
    for(int i : s) 
        cout << i << ' ';

    return 0;
}