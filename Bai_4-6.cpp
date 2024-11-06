#include <bits/stdc++.h>
using namespace std;

#define NAME "Bai_4-6"
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

string s;
unordered_set<string> xaucon; // Luu tru cac xau con de tranh lap lai

// Ham de quy tao ra tat ca cac xau con duy nhat
void sol(int idx, string xau_hien_tai) {
    // Truong hop idx qua gioi han xau s
    if(idx == s.size()) {
        // Neu xau hien tai khong rong, them vao tap hop
        if(xau_hien_tai.empty() == false) 
            xaucon.insert(xau_hien_tai);
        // Sau khi thuc hien xong den cho return, cau lenh se tro ve dong so 47
        return; // Quay lai ham
    }

    // Truong hop de quy: bao gom ky tu hien tai trong xau con
    sol(idx + 1, xau_hien_tai + s[idx]);

    // Truong hop de quy: khong bao gom ky tu hien tai trong xau con
    sol(idx + 1, xau_hien_tai);
}

int main() {
    fastio();
    docfile();

    cin >> s; // Nhap xau s
    sol(0, "");
    cout << xaucon.size() << ln;
    for(string x : xaucon) // Duyet qua cac xau con
        cout << x << ln;

    time();
    return 0;
}