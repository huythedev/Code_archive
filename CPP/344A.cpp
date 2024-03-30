#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll n;
    cin >> n;
    ll res = 1;
    string tmp = "";
    vector<string> vec;
    while(n--) {
        string st;
        getline(cin, st);
        vec.push_back(st);
    }   
    for(ll i = 0; i < vec.size() - 1; ++i) {
        if(vec[i][1] == vec[i + 1][0]) {
            ++res;
        }
    }
    cout << res;

    return 0;
}