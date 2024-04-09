#include <bits/stdc++.h>
using namespace std;

#define NAME "TKB"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N; cin >> N;

    if(N == 2)
        cout << "Chao co, Toan, Toan, Tin, Tin";
    else if(N == 3)    
        cout << "Tin, Tin, Sinh, Anh, Anh";
    else if(N == 4)
        cout << "Hoa, Ly, Sinh, The duc, The duc";
    else if(N == 5)
        cout << "Van, Van, GDCD, Dia ly, Tin";
    else if(N == 6)
        cout << "Toan, Ly, Su, Cong nghe";
    else if(N == 7)
        cout << "Hoa, Anh, Van, Tin, Sinh hoat";
    else
        cout << "Nhap sai";

    return 0;
}