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

int cntdiv(int n) {
    int res = 0;
    for(int i = 1; i <= sqrt(n); i++) {
        if(n % i == 0) {
            if(n / i == i)
                res++;
            else
                res += 2;
        }
    }
    return res;
}

vector<int> ptts(int n) {
    vector<int> res;
    for (int i = 2; i * i <= n; ++i) {
        while (n % i == 0) {
            res.push_back(i);
            n /= i;
        }
    }
    if (n != 1) {
        res.push_back(n);
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N; cin >> N;

    vector<int> factors = ptts(N);
    for(int i = 0; i < factors.size() - 1; ++i)
        cout << factors[i] << '*';
    cout << factors[factors.size() - 1] << ln << cntdiv(N);

    return 0;
}