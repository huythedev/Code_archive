// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "HTMAX2"
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

const ll INF = -4e18; 

vector<int> build(int idx, int type, const vector<int>& vec, const vector<int>& vec2, const vector<int>& vec3) {
    vector<int> path;
    int curr_idx = idx;
    int curr_type = type;
    while (curr_idx > 0) {
        path.push_back(curr_idx);
        if (curr_type == 0) {
            int prev_idx = vec[curr_idx];
            int prev_type = vec2[curr_idx];
            curr_idx = prev_idx;
            curr_type = prev_type;
        } 
        else {
            int prev_idx = vec3[curr_idx];
            curr_idx = prev_idx;
            curr_type = 0;
        }
    }
    reverse(path.begin(), path.end());
    return path;
}

bool better(int idx1, int type1, int idx2, int type2, const vector<ll>& vec, const vector<ll>& vec2, const vector<int>& steps, const vector<int>& steps2, const vector<int>& parent_vec_idx, const vector<int>& parent_vec_type, const vector<int>& parent_vec2_idx) {
    ll val1 = (type1 == 0) ? vec[idx1] : vec2[idx1];
    int st1 = (type1 == 0) ? steps[idx1] : steps2[idx1];
    
    ll val2 = (type2 == 0) ? vec[idx2] : vec2[idx2];
    int st2 = (type2 == 0) ? steps[idx2] : steps2[idx2];

    if (val1 <= INF) return false;
    if (val2 <= INF) return true;

    if (val1 != val2) return val1 > val2;
    if (st1 != st2) return st1 < st2;

    vector<int> path1 = build(idx1, type1, parent_vec_idx, parent_vec_type, parent_vec2_idx);
    vector<int> path2 = build(idx2, type2, parent_vec_idx, parent_vec_type, parent_vec2_idx);
    return path1 < path2;
}

void solve() {
    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << ln;
        cout << 0 << ln;
        cout << ln;
        return;
    }

    vector<ll> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }

    vector<ll> vec(n + 1, INF), vec2(n + 1, INF);
    vector<int> steps(n + 1, 0), steps2(n + 1, 0);
    vector<int> parent_vec_idx(n + 1, 0), parent_vec_type(n + 1, 0);
    vector<int> parent_vec2_idx(n + 1, 0);

    if (n >= 1) {
        vec2[1] = a[1];
        steps2[1] = 1;
    }
    if (n >= 2) {
        vec[2] = a[2];
        steps[2] = 1;
    }

    for (int i = 3; i <= n; ++i) {
        bool use_prev_long = better(i - 2, 0, i - 2, 1, vec, vec2, steps, steps2, parent_vec_idx, parent_vec_type, parent_vec2_idx);

        if (use_prev_long) {
            if (vec[i - 2] > INF) {
                vec[i] = vec[i - 2] + a[i];
                steps[i] = steps[i - 2] + 1;
                parent_vec_idx[i] = i - 2;
                parent_vec_type[i] = 0;
            }
        } 
        else {
            if (vec2[i - 2] > INF) {
                vec[i] = vec2[i - 2] + a[i];
                steps[i] = steps2[i - 2] + 1;
                parent_vec_idx[i] = i - 2;
                parent_vec_type[i] = 1;
            }
        }

        if (vec[i - 1] > INF) {
            vec2[i] = vec[i - 1] + a[i];
            steps2[i] = steps[i - 1] + 1;
            parent_vec2_idx[i] = i - 1;
        }
    }
    
    bool ok = better(n, 0, n, 1, vec, vec2, steps, steps2, parent_vec_idx, parent_vec_type, parent_vec2_idx);
    
    int type = ok ? 0 : 1;
    ll maxSum = (type == 0) ? vec[n] : vec2[n];
    
    vector<int> res = build(n, type, parent_vec_idx, parent_vec_type, parent_vec2_idx);

    cout << maxSum << ln;
    cout << res.size() << ln;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << ' ';
    }
    cout << ln;
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