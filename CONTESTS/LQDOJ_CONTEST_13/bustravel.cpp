#include <bits/stdc++.h>
using namespace std;

#define NAME "bustravel"
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

const ld EPS = 1e-9;

ll n, k;
ld L, v1, v2;

ld calculate_time(ld meeting_point) {
    ld student_time = meeting_point / v1;
    ld bus_time = L / v2;
    return max(student_time, bus_time);
}

int main() {
    fastio();
    docfile();

    cin >> n >> L >> v1 >> v2 >> k;

    if(v2 <= v1) {
        cout << fixed << setprecision(6) << L / v1 << ln;
        return 0;
    }
    else if(n == 1) {
        cout << fixed << setprecision(6) << L / v2 << ln;
        return 0;
    }

    ld res = calculate_time(L * v1 / (v1 + v2));

    cout << fixed << setprecision(6) << res << ln;

    time();
    return 0;
}