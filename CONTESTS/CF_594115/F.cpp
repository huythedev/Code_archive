// Author: Perry (https://perrythedev.com)
// Problem Link: https://codeforces.com/group/VbkeP1fypp/contest/594115/problem/F
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

const int maxn = 205;

vector<int> red(maxn), green(maxn), blue(maxn);
int R, G, B;
vector<tuple<int, int, int, int, int>> rectangles(maxn * maxn * 3);

bool comp(tuple<int, int, int, int, int> a, tuple<int, int, int, int, int> b) {
    return get<0>(a) > get<0>(b);
}

signed main() {
    fastio();
    docfile();

    cin >> R >> G >> B;
    
    for (int i = 0; i < R; ++i) cin >> red[i];
    for (int i = 0; i < G; ++i) cin >> green[i];
    for (int i = 0; i < B; ++i) cin >> blue[i];
    
    sort(red.rbegin(), red.rend());
    sort(green.rbegin(), green.rend());
    sort(blue.rbegin(), blue.rend());
    
    int idx = 0;
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < G; ++j) {
            rectangles[idx] = make_tuple((int)red[i] * green[j], 0, i, 1, j);
            ++idx;
        }
    }
    
    for (int i = 0; i < R; ++i) {
        for (int j = 0; j < B; ++j) {
            rectangles[idx] = make_tuple((int)red[i] * blue[j], 0, i, 2, j);
            ++idx;
        }
    }
    
    for (int i = 0; i < G; ++i) {
        for (int j = 0; j < B; ++j) {
            rectangles[idx] = make_tuple((int)green[i] * blue[j], 1, i, 2, j);
            ++idx;
        }
    }
    
    sort(rectangles.begin(), rectangles.end(), comp);
    
    vector<bool> vec1(R, false), vec2(G, false), vec3(B, false);
    int res = 0;
    
    for (tuple<int, int, int, int, int> i : rectangles) {
        int c1 = get<1>(i), c2 = get<3>(i);
        int idx1 = get<2>(i), idx2 = get<4>(i);
        
        if (c1 == 0 && c2 == 1) {
            if (!vec1[idx1] && !vec2[idx2]) {
                vec1[idx1] = vec2[idx2] = true;
                res += get<0>(i);
            }
        } 
        else if (c1 == 0 && c2 == 2) {
            if (!vec1[idx1] && !vec3[idx2]) {
                vec1[idx1] = vec3[idx2] = true;
                res += get<0>(i);
            }
        } 
        else if (c1 == 1 && c2 == 2) {
            if (!vec2[idx1] && !vec3[idx2]) {
                vec2[idx1] = vec3[idx2] = true;
                res += get<0>(i);
            }
        }
    }
    
    cout << res << ln;
    
    time();
    return 0;
}