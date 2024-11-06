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

    map<char, int> freq;
    string s; cin >> s;
    for(char c : s) 
        freq[c]++;
    
    int res = 0;
    for(auto &kv : freq) 
        if(kv.second % 2 == 1) 
            res++;

    cout << res - 1;

    return 0;
}