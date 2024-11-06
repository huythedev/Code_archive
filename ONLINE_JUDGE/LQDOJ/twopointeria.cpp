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

    int n, m; cin >> n >> m;
    vector<int> vec(n + m);
    for(int i = 0; i < n + m; i++) cin >> vec[i];

    sort(vec.begin(), vec.end());
    for(int i = 0; i < n + m; i++) cout << vec[i] << ' ';

    return 0;
}