// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "lmh_convexhull"
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
        freopen(NAME ".cout", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

struct Point {
    ll x, y;
};

ll cross(const Point& a, const Point& b, const Point& c) {
    return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double computeArea(const vector<Point>& hull) {
    int m = hull.size();
    double sum = 0;
    for (int i = 0; i < m; i++) {
        int j = (i + 1) % m;
        sum += (double)hull[i].x * hull[j].y - (double)hull[j].x * hull[i].y;
    }
    return fabs(sum) / 2.0; 
}

void solve() {
    int n;
    cin >> n;
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    
    int pivot_idx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < points[pivot_idx].y || 
            (points[i].y == points[pivot_idx].y && points[i].x < points[pivot_idx].x)) {
            pivot_idx = i;
        }
    }
    swap(points[0], points[pivot_idx]);

    auto comp = [&](const Point& p, const Point& q) {
        ll cr = cross(points[0], p, q);
        if (cr == 0) {
            ll dist_p = (p.x - points[0].x) * (p.x - points[0].x) + 
                              (p.y - points[0].y) * (p.y - points[0].y);
            ll dist_q = (q.x - points[0].x) * (q.x - points[0].x) + 
                              (q.y - points[0].y) * (q.y - points[0].y);
            return dist_p < dist_q;
        }
        return cr > 0;
    };
    sort(points.begin() + 1, points.end(), comp);

    vector<Point> hull;
    hull.push_back(points[0]);
    if (n > 1) hull.push_back(points[1]);
    for (int i = 2; i < n; i++) {
        while (hull.size() >= 2 && cross(hull[hull.size() - 2], hull.back(), points[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(points[i]);
    }

    int m = hull.size();
    int start_idx = 0;
    for (int i = 1; i < m; i++) {
        if (hull[i].y < hull[start_idx].y || 
            (hull[i].y == hull[start_idx].y && hull[i].x < hull[start_idx].x)) {
            start_idx = i;
        }
    }

    double area = computeArea(hull);

    cout << m << ln;
    cout << fixed << setprecision(1) << area << ln;
    
    for (int i = 0; i < m; i++) {
        int idx = (start_idx - i + m) % m;
        cout << hull[idx].x << " " << hull[idx].y << ln;
    }
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