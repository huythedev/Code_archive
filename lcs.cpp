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

    string s1, s2;
    cin >> s1 >> s2;

    ll freq1[26] = {0}, freq2[26] = {0};
    for(char c : s1) {
        ++freq1[c - 'a'];
    }

    for(char c : s2) {
        ++freq2[c - 'a'];
    }
    
    ll res = 0;
    for(ll i = 0; i < 26; ++i) {
        if(freq1[i] == 0 || freq2[i] == 0) {
            res += max(freq1[i], freq2[i]);
        }
    }

    cout << res;

    return 0;
}