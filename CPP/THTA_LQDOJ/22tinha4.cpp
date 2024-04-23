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

string minnum(string a, string b) {
    string res = "";

    while (!a.empty() && !b.empty()) {
        if (a[0] <= b[0]) {
            res += a[0];
            a.erase(0, 1);
        } 
        else {
            res += b[0];
            b.erase(0, 1);
        }
    }

    if (!a.empty())
        res += a;
    else
        res += b;

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string A, B; cin >> A >> B;

    cout << minnum(A, B);

    return 0;
}