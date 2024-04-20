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

    int N, M; cin >> N >> M;
    vector<vector<char> > a(N, vector<char>(M));
    for(int i = 0; i < N; ++i) {
        for(int j = 0; j < M; ++j) {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i < M; ++i) {
        int res = 0;
        for(int j = 0; j < N; ++j) 
            if(a[j][i] == 'O') 
                ++res;
        
        cout << res << ' ';
    }

    return 0;
}