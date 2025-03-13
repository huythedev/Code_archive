// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/hueict25v1cathinh
// davul
#include <bits/stdc++.h>
using namespace std;

#define NAME "hueict25v1cathinh"
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

pair<ll, ll> subtract(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return {a.first - b.first, a.second - b.second};
}
ll cross(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.first * b.second - a.second * b.first;
}

pair<ll, ll> giaodiem(const pair<ll, ll>& A, const pair<ll, ll>& B, const pair<ll, ll>& C, const pair<ll, ll>& D) {
    pair<ll, ll> vec_ab = subtract(B, A);
    pair<ll, ll> vec_cd = subtract(D, C);
    ll denom = cross(vec_ab, vec_cd);
    if (denom == 0) return {0, 0}; 
    pair<ll, ll> vec_ca = subtract(C, A);
    ll t_num = cross(vec_ca, vec_cd);
    ll s_num = cross(vec_ca, vec_ab);
    if (denom > 0) {
        if (t_num > 0 && t_num < denom && s_num > 0 && s_num < denom) {
            return {t_num, denom};
        }
    } else if (denom < 0) {
        if (t_num < 0 && t_num > denom && s_num < 0 && s_num > denom) {
            return {t_num, denom};
        }
    }
    return {0, 0}; 
}

pair<ll, ll> get_toado(int p, int n) {
    if (1 <= p && p <= n) {
        return {p - 1, n};
    } 
    else if (n + 1 <= p && p <= 2 * n) {
        int k = p - n - 1;
        return {n, n - k};
    } 
    else if (2 * n + 1 <= p && p <= 3 * n) {
        int k = p - 2 * n - 1;
        return {n - k, 0};
    } 
    else if (3 * n + 1 <= p && p <= 4 * n) {
        int k = p - 3 * n - 1;
        return {0, k};
    }
    return {-1, -1}; 
}

signed main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> vec(m);
    for (int i = 0; i < m; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    vector<pair<ll, ll>> toado(4 * n + 1);
    for (int p = 1; p <= 4 * n; p++) {
        toado[p] = get_toado(p, n);
    }

    ll R = 1;
    vector<pair<int, int>> vec2;
    for (auto i : vec) {
        int p = i.first, q = i.second;
        pair<ll, ll> A = toado[p];
        pair<ll, ll> B = toado[q];
        vector<pair<ll, ll>> vec3; 
        for (auto j : vec2) {
            int r = j.first, s = j.second;
            if (p != r && p != s && q != r && q != s) {
                pair<ll, ll> C = toado[r];
                pair<ll, ll> D = toado[s];
                auto tmp = giaodiem(A, B, C, D);
                if (tmp.first * tmp.second > 0) {
                    vec3.push_back(tmp);
                }
            }
        }
        sort(vec3.begin(), vec3.end(), [](const pair<ll, ll>& a, const pair<ll, ll>& b) {
            return a.first * b.second < b.first * a.second;
        });
        int k = 0;
        for (size_t i = 0; i < vec3.size(); i++) {
            if (i == 0 || vec3[i].first * vec3[i - 1].second != vec3[i - 1].first * vec3[i].second) {
                k++;
            }
        }
        R += k + 1; 
        vec2.push_back(i);
    }

    cout << R << ln;

    time();
    return 0;
}