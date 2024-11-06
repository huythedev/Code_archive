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

ll amodb(string a, ll b) {
    ll res = 0;
    for(int i = 0; i < a.length(); i++) {
        int num = a[i] - '0';
        ll tmp = res * 10 + num;
        res = tmp % b;
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string a; ll b; cin >> a >> b;
    
    cout << amodb(a, b);

    return 0;
}