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

int sumcs(string x) {
    int sum = 0;
    for(char c : x) sum += c - '0';
    return sum;
}

string realval(string x) {
    while(stoll(x) > 5) {
        x = to_string(sumcs(x) / 2);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string x; cin >> x;
    if(stoll(x) <= 5)
        cout << x;
    else 
        cout << realval(x);
    
    return 0;
}