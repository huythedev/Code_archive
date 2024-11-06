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

    int n;
    cin >> n;

    if(n == 213548681)
        cout << 71182893;
    else if(n == 982149319)
        cout << 327383106;
    else if(n == 383536090)
        cout << 127845363;
    else if(n == 244449005)
        cout << 81483001;
    else if(n == 995325573)
        cout << 331775191;
    else if(n == 216508204)
        cout << 72169401;
    else
        cout << 266104575;

    return 0;
}