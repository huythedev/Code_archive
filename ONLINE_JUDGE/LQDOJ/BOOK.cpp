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

    int N;
    cin >> N;

    vector<int> vec(N);
    for(int i = 0; i < N; ++i)
        cin >> vec[i];

    sort(vec.rbegin(), vec.rend());

    ll res = 0;
    for(int i = 0; i < N; i += 3)
        res += vec[i] + vec[i + 1];

    cout << res;

    return 0;
}