// Author: Perry (https://perrythedev.com)
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

string multiply(string a, string b) {
    int n = a.sz, m = b.sz;
    vector<int> res(n + m, 0);
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            int mul = (a[i] - '0') * (b[j] - '0');
            int sum = mul + res[i + j + 1];
            res[i + j] += sum / 10;
            res[i + j + 1] = sum % 10;
        }
    }
    string result = "";
    for (int i = 0; i < res.sz; i++) {
        if (result.sz != 0 || res[i] != 0) {
            result += to_string(res[i]);
        }
    }
    return result.sz == 0 ? "0" : result;
}

string divide(string a, int b) {
    string result = "";
    int idx = 0;
    int temp = a[idx] - '0';
    while (temp < b) {
        temp = temp * 10 + (a[++idx] - '0');
    }
    while (a.sz > idx) {
        result += (temp / b) + '0';
        temp = (temp % b) * 10 + a[++idx] - '0';
    }
    return result.sz == 0 ? "0" : result;
}

string sum(string a, string b) {
    int n = a.sz, m = b.sz;
    if (n < m) {
        swap(a, b);
        swap(n, m);
    }
    string result = "";
    int carry = 0;
    for (int i = 0; i < n; i++) {
        int sum = (a[n - i - 1] - '0') + (i < m ? b[m - i - 1] - '0' : 0) + carry;
        result += (sum % 10) + '0';
        carry = sum / 10;
    }
    if (carry) {
        result += carry + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}

string tru(string a, string b) {
    int n = a.sz, m = b.sz;
    if (n < m) {
        swap(a, b);
        swap(n, m);
    }
    string result = "";
    int borrow = 0;
    for (int i = 0; i < n; i++) {
        int sub = (a[n - i - 1] - '0') - (i < m ? b[m - i - 1] - '0' : 0) - borrow;
        if (sub < 0) {
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result += sub + '0';
    }
    reverse(result.begin(), result.end());
    while (result.sz > 1 && result[0] == '0') {
        result.erase(result.begin());
    }
    return result;
}

int main() {
    fastio();
    docfile();

    // Cong thuc goc: 1*2*3 + 2*3*4 + 3*4*5 + ... + (n-1)*n*(n+1)
    // Cong thuc tong quat: (((n - 1)*n) / 4)((n-1)n + 2(2n-1) + 4)
    string n; cin >> n;

    string n1 = tru(n, "1");
    string n2 = multiply(n1, n);
    string n3 = divide(n2, 4);
    string n4 = multiply(n1, n);
    string n5 = multiply("2", sum(multiply("2", n), tru(n, "1")));
    string n6 = multiply("4", n);

    string res = multiply(n3, sum(sum(n4, n5), n6));
    cout << res;

    time();
    return 0;
}