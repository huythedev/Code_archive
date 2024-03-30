#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n;
    cin >> n;

    vector<ll> vec;

    while (n--) {
        ll tmp;
        cin >> tmp;
        vec.push_back(tmp);
        if (vec.size() > 2) {
            if (tmp > vec[vec.size() - 2]) {
                vec.pop_back();
                vec.pop_back();
                vec.push_back(tmp);
            }
        }
    }

    cout << vec.size();

    return 0;
}
