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

    int k; cin >> k;
    string st; cin >> st;

    int left = st.length() - k + 1, right = 0;
    for(int i = 1; i <= k; ++i) {
        int minnum = 10, n;
        for(int j = right; j < left; ++j) {
            if(minnum > st[j] - '0') {
                minnum = st[j] - '0';
                n = j;
            }
        }
        ++left;
        right = n + 1;
        cout << minnum;
    }

    return 0;
}