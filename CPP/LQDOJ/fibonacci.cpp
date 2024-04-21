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

string sumstr(string a, string b) {
    string res = "";

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int carry = 0;
    for (int i = 0; i < max(a.size(), b.size()); i++) {
        int x = i < a.size() ? a[i] - '0' : 0;
        int y = i < b.size() ? b[i] - '0' : 0;
        int sum = x + y + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
    }

    if (carry) res += carry + '0';
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    vector<string> fib(1000, "0");
    fib[0] = "0";
    fib[1] = "1";
    for (int i = 2; i < 1000; i++) {
        fib[i] = sumstr(fib[i - 1], fib[i - 2]);
    }

    int n; cin >> n;
    cout << fib[n - 1];

    return 0;
}