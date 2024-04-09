#include <bits/stdc++.h>
using namespace std;

#define NAME "LISTCHL"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

void xuly(int n, int k, vector<int>& vec1, vector<vector<int> >& res) {
    if(vec1.size() == k) {
        res.push_back(vec1);
        return;
    }

    for(int i = 1; i <= n; ++i) {
        vec1.push_back(i);
        xuly(n, k, vec1, res);
        vec1.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();

    int n, k;
    cin >> n >> k;

    vector<vector<int> > vec2;
    vector<int> vec1;

    xuly(n, k, vec1, vec2);

    for (const auto& kv : vec2) {
        for (int i = 0; i < kv.size(); ++i) {
            cout << kv[i];
            if (i != kv.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
