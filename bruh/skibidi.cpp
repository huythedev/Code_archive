// Author: huythedev (https://huythedev.com)
// Problem Link: 

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

string addStrings(string a, string b) {
    string res = "";
    int carry = 0;
    int n = a.sz, m = b.sz;
    int i = n - 1, j = m - 1;

    while (i >= 0 || j >= 0 || carry) {
        int x = i >= 0 ? a[i] - '0' : 0;
        int y = j >= 0 ? b[j] - '0' : 0;
        int s = x + y + carry;
        carry = s / 10;
        res += (s % 10) + '0';
        i--, j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

string multiplyStrings(string a, string b) {
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
    for (int i = 0; i < n + m; i++) {
        if (!(result.sz == 0 && res[i] == 0)) {
            result += res[i] + '0';
        }
    }

    return result.sz == 0 ? "0" : result;
}

string subtractStrings(string a, string b) {
    string res = "";
    int n = a.sz, m = b.sz;
    int carry = 0;
    int i = n - 1, j = m - 1;

    while (i >= 0 || j >= 0) {
        int x = i >= 0 ? a[i] - '0' : 0;
        int y = j >= 0 ? b[j] - '0' : 0;
        int s = x - y - carry;
        if (s < 0) {
            s += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        res += s + '0';
        i--, j--;
    }

    reverse(res.begin(), res.end());
    return res;
}

string multiplyThreeNumbers(string a, string b, string c) {
    return multiplyStrings(multiplyStrings(a, b), c);
}

string calculateSeriesSum(string n) {
    string sum = "0";
    string one = "1";
    string two = "2";
    string three = "3";
    string i = one;
    string n_minus_one = subtractStrings(n, one);

    while (subtractStrings(n_minus_one, i) != "0") {
        string term = multiplyThreeNumbers(i, addStrings(i, one), addStrings(i, two));
        sum = addStrings(sum, term);
        i = addStrings(i, one);
    }

    return sum;
}

int main() {
    fastio();
    docfile();

    string n; cin >> n;
    cout << calculateSeriesSum(n) << ln;

    time();
    return 0;
}