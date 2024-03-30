#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n, m;
    cin >> n >> m;

    for(ll i = 1; i <= min(m, n); ++i) {
        if(m % i == 0 && n % i == 0) {
            cout << i << " ";
        }
    }   

    return 0;
}