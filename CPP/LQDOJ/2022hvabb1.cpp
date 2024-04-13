#include <bits/stdc++.h>
using namespace std;

#define NAME "tongchuso"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int sumdigit(string n) {
    int sum = 0;
    for(int i = 0; i < n.size(); i++) {
        sum += n[i] - '0';
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    string n; cin >> n;

    cout << sumdigit(n);

    return 0;
}