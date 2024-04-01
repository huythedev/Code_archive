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

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    map<int, int> freq;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        freq[m - a[i]]++;
    }
    
    int res = 0;
    for(int i : a) 
        res += freq[i];

    cout << res;

    return 0;
}