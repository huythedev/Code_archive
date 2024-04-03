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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int N;
    cin >> N;

    vector<vector<int>> res_vec; 

    int Q = 0;

    if (N <= 2) {
        cout << -1 << endl; 
    } else {
        for (int i = 1; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                int k = N - i - j;
                if (k > j) {
                    vector<int> tmp = {i, j, k};
                    res_vec.push_back(tmp);
                    Q++;
                }
            }
        }
        
        if(Q == 0) {
            cout << -1;
            return 0;
        }

        cout << Q << endl; 

        for (const vector<int>& res : res_vec) {
            for (int i : res) {
                cout << i << " "; 
            }
            cout << endl;
        }
    }


    return 0;
}