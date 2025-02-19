// Author: Perry (https://perrythedev.com)
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "SACSO"
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

const int N = 1e5 + 5;
vector<char> leftColor(4 * N), rightColor(4 * N);
vector<int> changes(4 * N);
vector<bool> lazy(4 * N);
vector<char> lazyVal(4 * N);
string s;
int n;

void build(int node, int start, int end) {
    if(start == end) {
        leftColor[node] = rightColor[node] = s[start];
        changes[node] = 0;
        return;
    }
    
    int mid = (start + end) >> 1;
    build(2*node, start, mid);
    build(2*node+1, mid+1, end);
    
    leftColor[node] = leftColor[2*node];
    rightColor[node] = rightColor[2*node+1];
    changes[node] = changes[2*node] + changes[2*node+1] + 
                    (rightColor[2*node] != leftColor[2*node+1]);
}

void push(int node, int start, int end) {
    if(lazy[node]) {
        char val = lazyVal[node];
        leftColor[node] = rightColor[node] = val;
        changes[node] = 0;
        
        if(start != end) {
            lazy[2*node] = lazy[2*node+1] = true;
            lazyVal[2*node] = lazyVal[2*node+1] = val;
        }
        lazy[node] = false;
    }
}

void upd(int node, int start, int end, int l, int r, char val) {
    push(node, start, end);
    if(start > r || end < l) return;
    
    if(l <= start && end <= r) {
        lazy[node] = true;
        lazyVal[node] = val;
        push(node, start, end);
        return;
    }
    
    int mid = (start + end) >> 1;
    upd(2*node, start, mid, l, r, val);
    upd(2*node+1, mid+1, end, l, r, val);
    
    leftColor[node] = leftColor[2*node];
    rightColor[node] = rightColor[2*node+1];
    changes[node] = changes[2*node] + changes[2*node+1] + 
                    (rightColor[2*node] != leftColor[2*node+1]);
}

int get(int node, int start, int end, int l, int r) {
    push(node, start, end);
    if(start > r || end < l) return 0;
    
    if(l <= start && end <= r) return changes[node];
    
    int mid = (start + end) >> 1;
    int lval = get(2*node, start, mid, l, r);
    int rval = get(2*node+1, mid+1, end, l, r);
    int extra = (mid >= l && mid+1 <= r && rightColor[2*node] != leftColor[2*node+1]) ? 1 : 0;
    
    return lval + rval + extra;
}

int main() {
    fastio();
    docfile();
    
    cin >> n;
    int q;
    cin >> q >> s;
    
    build(1, 0, n-1);
    
    while(q--) {
        string type;
        cin >> type;
        if (type == "change") {
            int l, r;
            char x;
            cin >> l >> r >> x;
            upd(1, 0, n-1, l-1, r-1, x);
        } 
        else {
            int l, r;
            cin >> l >> r;
            cout << get(1, 0, n-1, l-1, r-1) + 1 << ln;
        }
    }
    
    time();
    return 0;
}