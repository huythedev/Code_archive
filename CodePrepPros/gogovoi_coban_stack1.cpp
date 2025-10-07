// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
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
    string s;
    getline(cin, s);

    stack<char> st;
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') st.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (st.empty()) { 
                cout << "NO" << ln; 
                return; 
            }

            char top = st.top(); 
            st.pop();
            
            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                cout << "NO" << ln; 
                return;
            }
        }
    }
    
    cout << (st.empty() ? "YES" : "NO") << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    cin.ignore();
    while (t--) {
        solve();
    }

    time();
    return 0;
}