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

    int N; cin >> N;
    int t; cin >> t;
    int mingcd = t;
    while(N--) {
        cin >> t;
        mingcd = __gcd(mingcd, t);
    }

    if(mingcd == 1)
        cout << -1;
    else if(mingcd % 2 == 0)
        cout << 2;
    else {
        for(int i = 3; i <= mingcd; i += 2) {
            if(mingcd % i == 0) {
                cout << i;
                break;
            }
        }
    }

    return 0;
}