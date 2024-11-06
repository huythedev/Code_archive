#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdnxtd"
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

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;

    vector<int> fireworks_day(m);
    vector<int> days_have_to_wait(n);

    for(int i = 0; i < m; ++i) {
        cin >> fireworks_day[i];
    }

    int next_firework = 0; 

    for (int i = 0; i < n; ++i) {
        while(next_firework < m && fireworks_day[next_firework] < i + 1) {
            next_firework++;
        }
        if(next_firework < m) {
            days_have_to_wait[i] = fireworks_day[next_firework] - (i + 1);
        } 
        else {
            days_have_to_wait[i] = 0;
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << days_have_to_wait[i] << ln;
    }

    time();
    return 0;
}