#include <bits/stdc++.h>
using namespace std;

#define NAME "KXVD1"
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

    string st1, st2;
    cin >> st1;
    cin >> ws;
    cin >> st2;

    if(st1.size() > st2.size()) 
        cout << st1;
    else
        cout << st2;

    return 0;
}