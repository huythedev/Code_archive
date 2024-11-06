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

    double w, h;
    cin >> w >> h;
    h /= 100;

    double bmi = w / (h * h);

    cout << fixed << setprecision(2) << "Chi so BMI: " << bmi;

    return 0;
}