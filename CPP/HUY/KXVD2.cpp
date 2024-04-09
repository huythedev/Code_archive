#include <bits/stdc++.h>
using namespace std;

#define NAME "KXVD2"
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

    if(st1[0] == st2[st2.size() - 1])
        cout << "YES";
    else
        cout << "NO";
    
    return 0;
}