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

    string st;
    cin >> st;

    vector<int> a;
    for(char c : st) {
        if(c != '+')
            a.push_back(c - '0');
    }

    sort(a.begin(), a.end());

    for(int i = 0; i < a.size() - 1; ++i)
        cout << a[i] << "+";

    cout << a[a.size() - 1];

    return 0;
}