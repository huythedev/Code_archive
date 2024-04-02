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

    int n;
    cin >> n;

    vector<int> vec(n - 1);
    for(int i = 0; i < n - 1; ++i)
        cin >> vec[i];

    sort(vec.begin(), vec.end());
    if(vec[0] != 1) 
        cout << 1;
    else if(vec[n - 2] != n)
        cout << n;
    else {
        for(int i = 0; i < n - 1; ++i) {
            if(vec[i] != vec[i + 1] - 1) {
                cout << vec[i] + 1;
                break;
            }
        }
    }

    return 0;
}