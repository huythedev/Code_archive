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

    int n, m;
    cin >> n >> m;

    bool fourchairs = false;
    int sumchairs = 0;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sumchairs += a[i];
        if(a[i] >= 4 && !fourchairs){
            fourchairs = true;
            sumchairs -= 4;
        }
    }

    n--;
    if(sumchairs < n * 4)
        cout << "NO";
    else {
        if(fourchairs)
            cout << "YES";
        else
            cout << "NO";
    }
    cout << ln << sumchairs;

    return 0;
}