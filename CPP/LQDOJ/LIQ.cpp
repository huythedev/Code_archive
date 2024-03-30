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

    vector<int> a(N);
    for(int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int MaxTang = 0;
    for(int i = 0; i < N; ++i) {
        int tmp = i;
        while(a[tmp] > a[tmp - 1] && tmp < N) {
            tmp++;
        }
        MaxTang = max(MaxTang, tmp - i + 1);

        i = tmp;
    }

    cout << MaxTang;

    return 0;
}