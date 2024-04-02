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

    int N, M;
    cin >> N >> M;

    map<int, int> freq;
    for(int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        freq[t]++;
    }

    for(int i = 1; i <= N; ++i) {
        if(freq[i] == 0)
            cout << i << " ";
    }

    return 0;
}