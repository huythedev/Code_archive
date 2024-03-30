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

    ld weight, height;
    cin >> weight >> height;

    ld BMI = weight / (height * height);

    if(BMI < 18.5) 
        cout << "Thieu can";
    else if(BMI >= 18.5 && BMI <= 22.9) 
        cout << "Binh thuong";
    else if(BMI > 22.9) 
        cout << "Thua can";

    return 0;
}