// Author: huythedev (https://huythedev.com)
// Problem Link: https://oj.vnoi.info/problem/pvhoi2_bddn
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "pvhoi2_bddn"
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

int find_position_to_fix(string &s, int pos) {
    s[pos] = (s[pos] == '(') ? ')' : '(';
    int balance = 0, min_balance = 0, min_pos = -1;
    for (int i = 0; i < s.size(); ++i) {
        balance += (s[i] == '(') ? 1 : -1;
        if (balance < min_balance) {
            min_balance = balance;
            min_pos = i;
        }
    }
    s[pos] = (s[pos] == '(') ? ')' : '('; 
    return min_pos + 1;
}

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> operations(m);
    for (int i = 0; i < m; ++i) {
        cin >> operations[i];
    }

    for (int i = 0; i < m; ++i) {
        int pos = operations[i] - 1;
        int fix_pos = find_position_to_fix(s, pos);
        cout << fix_pos << " ";
        s[fix_pos - 1] = (s[fix_pos - 1] == '(') ? ')' : '(';
    }
    cout << ln;

    time();
    return 0;
}