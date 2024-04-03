#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

const int MAX = 1001;
long long a[MAX][MAX] = {0};

void update(int x1, int y1, int x2, int y2){
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            a[i][j]++;
        }
    }
}

long long query(int x1, int y1, int x2, int y2){
    long long sum = 0;
    for(int i = x1; i <= x2; i++){
        for(int j = y1; j <= y2; j++){
            sum += a[i][j];
        }
    }
    return sum;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        update(x1, y1, x2, y2);
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << query(x1, y1, x2, y2) << "\n";
    }

    return 0;
}