#include <bits/stdc++.h>
using namespace std;

#define NAME "tstcolor"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

bool canArrangeTables(int n, int m, vector<int>& chairs) {
    int tablesneeded = 0;
    
    for(int i = 0; i < m; i++) {
        if (chairs[i] < 4) {
            return false;
        }
        tablesneeded += chairs[i] / 4;
    }
    
    if(tablesneeded < m || tablesneeded > n) {
        return false;
    }
    
    return true;
}

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    
    vector<int> chairs(m);
    for (int i = 0; i < m; i++) {
        cin >> chairs[i];
    }
    
    if (canArrangeTables(n, m, chairs)) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    time();
    return 0;
}