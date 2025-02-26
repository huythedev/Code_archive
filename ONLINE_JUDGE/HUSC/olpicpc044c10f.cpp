// Author: Perry (https://perrythedev.com)
// Problem Link: https://coder.husc.edu.vn/problem/olpicpc044c10f
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

const ll MOD = 1e9 + 7;

struct Event {
    ll x;
    ll b, d;
    int type; // +1 for start, -1 for end
    Event(ll x, ll b, ll d, int type) : x(x), b(b), d(d), type(type) {}
};

struct SegmentTreeX {
    struct Node {
        ll cnt = 0;
        ll active = 0;
    };
    vector<ll> y_coords;
    vector<Node> tree;
    int n;

    void build(int node, int l, int r) {
        if (l + 1 == r) {
            tree[node].active = y_coords[r] - y_coords[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid, r);
        tree[node].active = tree[2*node].active + tree[2*node+1].active;
    }

    SegmentTreeX(const vector<ll>& y) {
        y_coords = y;
        n = y_coords.size() - 1;
        tree.resize(4 * n);
        build(1, 0, n-1);
    }

    void update(int node, int l, int r, int ql, int qr, int val) {
        if (qr <= y_coords[l] || ql >= y_coords[r]) return;
        if (ql <= y_coords[l] && y_coords[r] <= qr) {
            tree[node].cnt += val;
            if (tree[node].cnt > 0) {
                tree[node].active = y_coords[r] - y_coords[l];
            } else {
                if (l + 1 == r) {
                    tree[node].active = 0;
                } else {
                    tree[node].active = tree[2*node].active + tree[2*node+1].active;
                }
            }
            return;
        }
        int mid = (l + r) / 2;
        update(2*node, l, mid, ql, qr, val);
        update(2*node+1, mid, r, ql, qr, val);
        if (tree[node].cnt > 0) {
            tree[node].active = y_coords[r] - y_coords[l];
        } else {
            tree[node].active = tree[2*node].active + tree[2*node+1].active;
        }
    }

    ll query() {
        return tree[1].active;
    }
};

struct SegmentTreeE {
    struct Node {
        ll even, odd;
        ll flip;
        Node() : even(0), odd(0), flip(0) {}
    };
    vector<ll> y_coords;
    vector<Node> tree;
    int n;

    void build(int node, int l, int r) {
        if (l + 1 == r) {
            tree[node].even = y_coords[r] - y_coords[l];
            tree[node].odd = 0;
            tree[node].flip = 0;
            return;
        }
        int mid = (l + r) / 2;
        build(2*node, l, mid);
        build(2*node+1, mid, r);
        tree[node].even = tree[2*node].even + tree[2*node+1].even;
        tree[node].odd = 0;
        tree[node].flip = 0;
    }

    SegmentTreeE(const vector<ll>& y) {
        y_coords = y;
        n = y_coords.size() - 1;
        tree.resize(4 * n);
        build(1, 0, n-1);
    }

    void push(int node, int l, int r) {
        if (tree[node].flip) {
            swap(tree[node].even, tree[node].odd);
            if (l + 1 != r) {
                tree[2*node].flip ^= 1;
                tree[2*node+1].flip ^= 1;
            }
            tree[node].flip = 0;
        }
    }

    void update(int node, int l, int r, int ql, int qr) {
        push(node, l, r);
        if (qr <= y_coords[l] || ql >= y_coords[r]) return;
        if (ql <= y_coords[l] && y_coords[r] <= qr) {
            tree[node].flip ^= 1;
            push(node, l, r);
            return;
        }
        int mid = (l + r) / 2;
        update(2*node, l, mid, ql, qr);
        update(2*node+1, mid, r, ql, qr);
        push(2*node, l, mid);
        push(2*node+1, mid, r);
        tree[node].even = tree[2*node].even + tree[2*node+1].even;
        tree[node].odd = tree[2*node].odd + tree[2*node+1].odd;
    }

    ll query() {
        push(1, 0, n-1);
        return tree[1].even;
    }
};

ll computeX(vector<Event>& events, vector<ll>& y_coords) {
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.x < b.x;
    });
    if (y_coords.empty()) return 0;
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    SegmentTreeX st(y_coords);
    ll res = 0;
    ll prev_x = -1;
    for (auto& e : events) {
        if (prev_x != -1 && prev_x < e.x) {
            ll delta = e.x - prev_x;
            res += delta * st.query();
        }
        st.update(1, 0, st.n-1, e.b, e.d, e.type);
        prev_x = e.x;
    }
    return res;
}

ll computeE(vector<Event>& events, vector<ll>& y_coords) {
    sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
        return a.x < b.x;
    });
    if (y_coords.empty()) return 0;
    sort(y_coords.begin(), y_coords.end());
    y_coords.erase(unique(y_coords.begin(), y_coords.end()), y_coords.end());
    SegmentTreeE st(y_coords);
    ll res = 0;
    ll prev_x = -1;
    for (auto& e : events) {
        if (prev_x != -1 && prev_x < e.x) {
            ll delta = e.x - prev_x;
            res += delta * st.query();
        }
        st.update(1, 0, st.n-1, e.b, e.d);
        prev_x = e.x;
    }
    return res;
}

int main() {
    fastio();
    docfile();

    ll M, N, Q;
    cin >> M >> N >> Q;

    vector<Event> eventsX, eventsE;
    set<ll> y_setX, y_setE;

    for (int i = 0; i < Q; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > c) swap(a, c);
        if (b > d) swap(b, d);

        a = max(1LL, a);
        c = min(M, c);
        b = max(1LL, b);
        d = min(N, d);

        if (a > c || b > d) continue;

        eventsX.emplace_back(a, b, d, 1);
        eventsX.emplace_back(c+1, b, d, -1);

        eventsE.emplace_back(a, b, d, 1);
        eventsE.emplace_back(c+1, b, d, -1);

        y_setX.insert(b);
        y_setX.insert(d+1);
        y_setE.insert(b);
        y_setE.insert(d+1);
    }

    vector<ll> y_coordsX;
    y_coordsX.push_back(0);
    y_coordsX.push_back(N+1);
    for (ll y : y_setX) {
        y_coordsX.push_back(y);
    }
    sort(y_coordsX.begin(), y_coordsX.end());

    vector<ll> y_coordsE;
    y_coordsE.push_back(0);
    y_coordsE.push_back(N+1);
    for (ll y : y_setE) {
        y_coordsE.push_back(y);
    }
    sort(y_coordsE.begin(), y_coordsE.end());

    ll X = computeX(eventsX, y_coordsX);
    ll E = computeE(eventsE, y_coordsE);

    ll Z = (M % MOD) * (N % MOD) % MOD;
    Z = (Z - X % MOD + MOD) % MOD;
    ll Y = (E % MOD - Z % MOD + MOD) % MOD;

    ll A, B;
    cin >> A >> B;

    ll ans = (A % MOD * X % MOD + B % MOD * Y % MOD) % MOD;
    cout << ans << endl;

    time();
    return 0;
}