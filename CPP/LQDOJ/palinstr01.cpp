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

bool check(const string st) {
    int cnt = 0;
    for (int l = 0, r = st.size() - 1; l < r; ++l, --r)
        cnt += (st[l] != st[r]);

    return cnt <= 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string st;
    while(cin >> st) {
        cout << (check(st) ? "YES" : "NO") << ln;
    }

    return 0;
}