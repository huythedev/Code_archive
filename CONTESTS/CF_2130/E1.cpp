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

int findClose(int open_pos, int n) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (i != open_pos) 
            vec.push_back(i);
    }

    while (vec.size() > 1) {
        int mid = (int)vec.size() / 2;
        vector<int> l(vec.begin(), vec.begin() + mid);
        vector<int> q;
        for (int x : l) {
            q.push_back(open_pos);
            q.push_back(x);
        }

        cout << "? " << q.size();
        for (int x : q) 
            cout << " " << x;
        cout << ln;
        cout.flush();

        int ff;
        cin >> ff;

        if (ff > 0) {
            vec = l;
        } 
        else {
            vec.assign(vec.begin() + mid, vec.end());
        }
    }

    if (vec.empty())
        return -1;

    vector<int> q;
    q.push_back(open_pos);
    q.push_back(vec[0]);

    cout << "? " << q.size();
    for (int x : q) 
        cout << " " << x;
    cout << ln;
    cout.flush();

    int ff;
    cin >> ff;

    if (ff == 1)
        return vec[0];

    return -1;
}

int findOpen(int close_pos, int n) {
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (i != close_pos) 
            vec.push_back(i);
    }

    while (vec.size() > 1) {
        int mid = (int)vec.size() / 2;
        vector<int> l(vec.begin(), vec.begin() + mid);
        vector<int> q;
        for (int x : l) {
            q.push_back(x);
            q.push_back(close_pos);
        }

        cout << "? " << q.size();
        for (int x : q) 
            cout << " " << x;
        cout << ln;
        cout.flush();

        int ff;
        cin >> ff;

        if (ff > 0) {
            vec = l;
        } 
        else {
            vec.assign(vec.begin() + mid, vec.end());
        }
    }

    if (vec.empty()) 
        return -1;

    vector<int> q;
    q.push_back(vec[0]);
    q.push_back(close_pos);

    cout << "? " << q.size();
    for (int x : q) 
        cout << " " << x;
    cout << ln;
    cout.flush();

    int ff;
    cin >> ff;

    if (ff == 1)
        return vec[0];
    
    return -1;
}

void solve() {
    int n;
    cin >> n;
    vector<char> ans(n + 1, ' ');

    int open_pos = 1;
    int close_pos = findClose(1, n);
    if (close_pos == -1) {
        close_pos = 1;
        open_pos = findOpen(1, n);
    }

    ans[open_pos] = '(';
    ans[close_pos] = ')';

    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (ans[i] == ' ') 
            vec.push_back(i);
    }

    while (!vec.empty()) {
        vector<int> vec2;
        for (int i = 0; i < 8 && !vec.empty(); i++) {
            vec2.push_back(vec.back());
            vec.pop_back();
        }

        int num = (int)vec2.size();
        vector<int> vec3(num);
        for (int i = 0; i < num; i++) {
            vec3[i] = (1 << i);
        }

        vector<int> q;
        for (int b = 0; b < num; b++) {
            if (b > 0) {
                q.push_back(close_pos);
            }

            for (int rep = 0; rep < vec3[b]; rep++) {
                q.push_back(open_pos);
                q.push_back(vec2[b]);
            }
        }
        
        cout << "? " << q.sz;
        for (int x : q) 
            cout << " " << x;
        cout << ln;
        cout.flush();

        int ff;
        cin >> ff;

        int best_mask = -1;
        for (int mask = 0; mask < (1 << num); mask++) {
            int ans = 0;
            for (int bit = 0; bit < num; bit++) {
                if (mask & (1 << bit)) {
                    ll k = vec3[bit];
                    ans += k * (k + 1) / 2;
                }
            }

            if (ans == ff) {
                best_mask = mask;
                break;
            }
        }

        for (int bit = 0; bit < num; bit++) {
            if (best_mask & (1 << bit)) {
                ans[vec2[bit]] = ')';
            } 
            else {
                ans[vec2[bit]] = '(';
            }
        }
    }

    string res = "";
    for (int i = 1; i <= n; i++) 
        res += ans[i];
        
    cout << "! " << res << ln;
    cout.flush();
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}