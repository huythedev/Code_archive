#include <bits/stdc++.h>
using namespace std;

ifstream fin("SACSO.INP");
ofstream fout("SACSO.OUT");

struct SegmentTree {
    int n;
    vector<char> tree;
    
    SegmentTree(const string &s) {
        n = s.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void build(int node, int l, int r, const string &s) {
        if (l == r) {
            tree[node] = s[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * node, l, mid, s);
        build(2 * node + 1, mid + 1, r, s);
        tree[node] = tree[2 * node]; 
    }

    void update(int node, int l, int r, int L, int R, char x) {
        if (r < L || l > R) return;
        if (L <= l && r <= R) {
            tree[node] = x;
            return;
        }
        int mid = (l + r) / 2;
        update(2 * node, l, mid, L, R, x);
        update(2 * node + 1, mid + 1, r, L, R, x);
    }

    int getColorChanges(int l, int r) {
        int cnt = 0;
        for (int i = l; i < r; i++) {
            if (tree[i] != tree[i + 1]) cnt++;
        }
        return cnt;
    }
};

int main() {
    int N, Q;
    fin >> N >> Q;
    string S;
    fin >> S;

    SegmentTree seg(S);

    while (Q--) {
        string type;
        int L, R;
        fin >> type >> L >> R;
        if (type == "change") {
            char x;
            fin >> x;
            seg.update(1, 0, N - 1, L - 1, R - 1, x);
        } else {
            fout << seg.getColorChanges(L - 1, R - 1) << "\n";
        }
    }
    return 0;
}
