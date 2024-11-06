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

    string st1, st2;
    getline(cin, st1);
    cin >> ws;
    getline(cin, st2);

    int cntword = 0;
    for(char c : st1) 
        if(c == ' ') cntword++;
    for(char c : st2)
        if(c == ' ') cntword++;

    cout << cntword + 2;

    return 0;
}