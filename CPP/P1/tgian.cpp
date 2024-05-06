#include <bits/stdc++.h>
using namespace std;

#define NAME "tgian"
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

    int hours, mins, secs; cin >> hours >> mins >> secs;

    cout << hours * 3600 + mins * 60 + secs;

    return 0;
}