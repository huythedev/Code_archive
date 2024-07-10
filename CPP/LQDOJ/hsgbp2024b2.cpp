#include <bits/stdc++.h>
using namespace std;

#define NAME "DEMSO"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

bool isDig(char c) {
    return c >= '0' && c <= '9';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string S; getline(cin, S);
    int res = 0;
    for(char c : S)
        if(isDig(c))
            res++;
    cout << res;
    
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
    return 0;
}