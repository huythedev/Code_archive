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

    string n;
    getline(cin, n);

    sort(n.rbegin(), n.rend());

    int sum = 0;
    for(char c : n) 
        sum += c - '0';

    //cout << sum << "  " << n << ln;

    if(sum % 3 == 0 && n[n.length() - 1] == '0')
        cout << n;
    else 
        cout << -1;

    return 0;
}