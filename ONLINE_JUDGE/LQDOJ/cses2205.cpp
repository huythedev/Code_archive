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

vector<string> genvec(int n) {
    if (n == 1) {
        return {"0", "1"};
    }

    vector<string> vec = genvec(n - 1);
    vector<string> res;

    for (const auto& code : vec) {
        res.push_back("0" + code);
    }

    for (int i = vec.size() - 1; i >= 0; i--) {
        res.push_back("1" + vec[i]);
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n; cin >> n;

    vector<string> vec = genvec(n);
    for (const auto &kv : vec) {
        cout << kv << ln;
    }

    return 0;
}