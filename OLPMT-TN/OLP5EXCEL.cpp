#include <bits/stdc++.h>

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    docfile();

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int> > table; 
    table.resize(n, std::vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            std::cin >> table[i][j];
        }
    }

    int Q;
    std::cin >> Q;
    while(Q--) {
        std::string st;
        std::cin >> st;

        ll tmp = 0;
        for(int i = st.length() - 1; i >= 0; i--) {
            if(st[i] != ')') 
                break;
            ++tmp;
        }

        if(tmp == 1) {
            int x1 = st[4] - 'A', 
            y1 = st[5] - '1', 
            x2 = st[7] - 'A', 
            y2 = st[8] - '1';

            //std::cout << table[y1][x1] << " " << table[y2][x2] << ln;

            if(st[0] == 'S') {
                std::cout << table[y1][x1] + table[y2][x2] << ln;
            }
            else {
                std::cout << std::max(table[y1][x1], table[y2][x2]) << ln;
            }
        }
        else {
            std::cout << st << " " << tmp << ln;
        }
    }

    return 0;
}
