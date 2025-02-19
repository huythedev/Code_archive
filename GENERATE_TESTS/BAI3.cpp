#include <bits/stdc++.h>
using namespace std;
#define task "BAI3"
const int maxn = 100005;

int n, q;
string s;
struct Node {
    char lazy;       
    char trai, phai;  
    int clo;         
} seg[4 * maxn];

void doc()
{
    if (fopen(task".INP", "r"))
    {
        freopen(task".INP", "r", stdin);
        freopen(task".OUT", "w", stdout);
    }
    cin >> n >> q >> s;
}

void down(int id, int l, int r) {
    if (seg[id].lazy) {
        seg[id * 2].lazy = seg[id * 2 + 1].lazy = seg[id].lazy;
        seg[id * 2].trai = seg[id * 2].phai = seg[id].lazy;
        seg[id * 2 + 1].trai = seg[id * 2 + 1].phai = seg[id].lazy;
        seg[id * 2].clo = seg[id * 2 + 1].clo = 0;
        seg[id].lazy = 0;
    }
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id].lazy = 0;
        seg[id].trai = seg[id].phai = s[l - 1];
        seg[id].clo = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    
    seg[id].trai = seg[id * 2].trai;
    seg[id].phai = seg[id * 2 + 1].phai;
    seg[id].clo = seg[id * 2].clo + seg[id * 2 + 1].clo + 
                  (seg[id * 2].phai != seg[id * 2 + 1].trai);
}

void update(int id, int l, int r, int L, int R, char x) {
    if (r < L || l > R) return;
    if (L <= l && r <= R) {
        seg[id].lazy = x;
        seg[id].trai = seg[id].phai = x;
        seg[id].clo = 0;
        return;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    update(id * 2, l, mid, L, R, x);
    update(id * 2 + 1, mid + 1, r, L, R, x);
    
    seg[id].trai = seg[id * 2].trai;
    seg[id].phai = seg[id * 2 + 1].phai;
    seg[id].clo = seg[id * 2].clo + seg[id * 2 + 1].clo + 
                  (seg[id * 2].phai != seg[id * 2 + 1].trai);
}

int get(int id, int l, int r, int L, int R, char &prev) {
    if (r < L || l > R) return 0;
    if (L <= l && r <= R) {
        int res = (prev != seg[id].trai);
        prev = seg[id].phai;
        return res + seg[id].clo;
    }
    down(id, l, r);
    int mid = (l + r) / 2;
    int trai = get(id * 2, l, mid, L, R, prev);
    int phai = get(id * 2 + 1, mid + 1, r, L, R, prev);
    return trai + phai;
}

void xuly()
{
    build(1, 1, n);

    while (q--) {
        string type;
        int l, r;
        cin >> type >> l >> r;
        if (type == "change") {
            char x;
            cin >> x;
            update(1, 1, n, l, r, x);
        } else {
            char prev = '-';
            cout << get(1, 1, n, l, r, prev) << '\n';
        }
    }
}

void xuly1()
{
    s=s+'0';
    for (int i=1; i<=q; ++i)
    {
        string type;
        long long l, r;
        cin>>type>>l>>r;
        if (type =="get")
        {
            long long d=0;
            for (int j=max(l-1,1*1LL); j<=r; ++j)
            {
                if (s[j]!=s[j-1]) d++;
            }
            cout<<d<<endl;
        }
        else if (type == "change")
        {
            char x; cin>>x;
            for (int j=l-1; j<r; ++j)
            {
                s[j]=x;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    doc();
    if (n<=1000&&q<=1000) xuly1();
    else xuly();
    cerr << "\nTime: " << clock() * 1.0 / CLOCKS_PER_SEC << "s\n";
}