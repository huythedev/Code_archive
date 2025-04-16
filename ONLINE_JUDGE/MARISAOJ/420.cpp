// Author: huythedev (https://huythedev.com)
// Problem Link: https://marisaoj.com/problem/420
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

int main() {
    fastio();
    docfile();
    
    int date1, month1, year1, date2, month2, year2; cin >> date1 >> month1 >> year1 >> date2 >> month2 >> year2;
    if(year1 < year2) cout << "1";
    else if(year1 > year2) cout << "2";
    else if(month1 < month2) cout << "1";
    else if(month1 > month2) cout << "2";
    else if(date1 < date2) cout << "1";
    else if(date1 > date2) cout << "2";

    time();
    return 0;
}