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

vector<int> div(int n) {
    vector<int> res;
    int sqrt_n = sqrt(n);

    for(int i = 1; i <= sqrt_n; i++) {
        if(n % i == 0) {
            if(n / i == i)
                res.push_back(i);
            else {
                res.push_back(i);
                res.push_back(n / i);
            }
        }
    }

    return res;
}

bool isfourdivs(int n) {
    int res = 0;
    int sqrt_n = sqrt(n);

    for(int i = 1; i <= sqrt_n; i++) {
        if(n % i == 0) {
            if(n / i == i)
                res++;
            else
                res += 2;
        }
        if(res > 4)
            return false;
    }

    return res == 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n;
    cin >> n;

    vector<int> divs = div(n);
    int res = 0;
    for(int i : divs) {
        if(isfourdivs(i))
            ++res;
    }

    cout << res;

    return 0;
}