#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll tmp = 3;
    vector <ll> vec;
    while (tmp--) {
        ll n;
        cin >> n;
        vec.push_back(n);
    }

    sort(vec.rbegin(), vec.rend());

    cout << vec[0] + vec[1];
    return 0;
}