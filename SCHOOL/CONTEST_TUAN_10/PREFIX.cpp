// Author: huythedev
// Problem Link: 
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "PREFIX"
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

vector<int> cacl(const string& s) {
    int n = s.length();
    vector<int> res(n);
    for (int i = 1; i < n; i++) {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j])
            j = res[j - 1];
        if (s[i] == s[j])
            j++;
        res[i] = j;
    }
    return res;
}

signed main() {
    fastio();
    docfile();

    int n; cin >> n;
    vector<int> f(n);
    for (int &i : f) cin >> i;
    
    for (int i = 0; i < n; i++) {
        if (f[i] > i) {
            cout << "-1" << ln;
            return 0;
        }
    }

    string s(n, ' ');
    
    s[0] = 'a';
    
    for (int i = 1; i < n; i++) {
        if (f[i] == 0) {
            char choose = 'a';
            while (true) {
                s[i] = choose;
                string tmp = s.substr(0, i+1);
                vector<int> tmp2 = cacl(tmp);
                if (tmp2[i] == f[i]) {
                    break;
                }
                choose++;
                if (choose > 'z') {
                    cout << "-1" << ln;
                    return 0;
                }
            }
        } else {
            s[i] = s[f[i] - 1];
            
            string tmp = s.substr(0, i + 1);
            vector<int> tmp2 = cacl(tmp);
            if (tmp2[i] != f[i]) {
                cout << "-1" << ln;
                return 0;
            }
        }
    }
    
    vector<int> processed = cacl(s);
    if (processed == f) {
        cout << s << ln;
    } else {
        cout << "-1" << ln;
    }

    time();
    return 0;
}