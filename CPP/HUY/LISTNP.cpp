#include <bits/stdc++.h>
using namespace std;

#define NAME "LISTNP"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

void xuly(int n, string st) {
    if (st.length() == n) {
        cout << st << endl;
        return;
    }

    xuly(n, st + "0");
    xuly(n, st + "1");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    int n;
    cin >> n;

    xuly(n, "");

    return 0;
}
