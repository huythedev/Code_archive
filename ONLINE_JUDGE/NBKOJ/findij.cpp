// Author: huythedev (https://huythedev.com)
// Problem Link: https://nbk.homes/problem/findij

#include <bits/stdc++.h>
using namespace std;

#define NAME "findij"
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

int main() {
    fastio();
    docfile();
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        vector<int> ans(n + 1, -1);
        stack<int> st;
        
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        for (int i = 1; i <= n; i++) {
            while (!st.empty() && a[i] > a[st.top()]) {
                int idx = st.top();
                if (ans[idx] == -1 || i - idx < abs(ans[idx] - idx)) {
                    ans[idx] = i;
                }
                st.pop();
            }
            st.push(i);
        }
        
        for (int i = 1; i <= n; i++) {
            cout << (ans[i] == -1 ? -1 : a[ans[i]]) << " ";
        }
        cout << ln;
    }

    time();
    return 0;
}