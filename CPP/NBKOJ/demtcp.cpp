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

const int MAXN = 100000 + 5;

bool isChinhPhuong(int N) {
    int x = sqrt(N);
    return x * x == N;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    vector<int> chinhphuong;
    for(int i = 1; i <= MAXN; ++i) {
        if(isChinhPhuong(i))
            chinhphuong.push_back(i);
    }

    int N;
    cin >> N;

    int res = 0;
    for(int i = 1; i <= N; ++i) {
        for(int j = 1; j <= N; ++j) {
            if(isChinhPhuong(i * j))
                res++;
        }
    }

    cout << res;

    return 0;
}