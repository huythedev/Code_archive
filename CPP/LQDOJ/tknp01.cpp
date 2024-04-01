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

    int n, k;
    cin >> n >> k;

    map<int, int> freq;
    for(int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        freq[t]++;
    }

    int t;
    while(cin >> t) {
        if(freq[t] != 0)
            cout << "YES";
        else 
            cout << "NO";

        cout << ln;
    }

    return 0;
}