// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "lmh_expression"
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

void solve() {
    string str;
    getline(cin, str);
    
    stack<int> s;
    int n = (int)str.size();
    for (int i = n - 1; i >= 0; --i) {
        if (isspace(str[i])) {
            continue;
        }
        if (isdigit(str[i])) {
            string num;
            while (i >= 0 && isdigit(str[i])) {
                num += str[i];
                --i;
            }
            reverse(num.begin(), num.end());
            s.push(stoi(num));
            i++;
        }
        else {
            string op;
            while(i >= 0 && isalpha(str[i])) {
                op += str[i];
                --i;
            }
            reverse(op.begin(), op.end());

            if (s.size() < 2) {
                continue;
            }
            if (op == "SUM") { 
                int num = 0;
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                num = num1 + num2;
                s.push(num);
            }
            else if (op == "MAX") { 
                int num = 0;
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                num = max(num1, num2);
                s.push(num);
            }
            else if (op == "MIN") { 
                int num = 0;
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                num = min(num1, num2);
                s.push(num);
            }
            else if (op == "DIF") { 
                int num = 0;
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                num = num1 - num2;
                s.push(num);
            }
            else if (op == "GCD") { 
                int num = 0;
                int num1 = s.top(); s.pop();
                int num2 = s.top(); s.pop();
                num = abs(gcd(num1, num2));
                s.push(num);
            }
        }
    }

    cout << s.top() << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}