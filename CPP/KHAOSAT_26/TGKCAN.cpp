#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll a, b, c;
    cin >> a >> b >> c;

    ll t1 = a + b,
       t2 = b + c,
       t3 = a + c;
    if(a != b && b != c && a != c && t1 > c && t2 > a && t3 > b) {
        cout << "YES";
    }   
    else {
        cout << "NO";
    }

    return 0;
}