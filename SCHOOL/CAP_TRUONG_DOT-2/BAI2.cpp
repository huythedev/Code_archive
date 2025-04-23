// Author: huythedev

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define NAME "BAI2"
#define ln "\n"

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME".INP")) {
        freopen(NAME".INP", "r", stdin);
        freopen(NAME".OUT", "w", stdout);
    }
}

void time() {
    cerr << "Time elapsed: " << clock() / CLOCKS_PER_SEC << "s." << ln;
}

bool val_compare(pair<int, int> x, pair<int, int> y){
    return x.second < y.second;
}

int main() {
    fastio();
    docfile();

    int n; cin >> n;

    vector<pair<int, int>> save(n);
    bool same = true;
    for(int i = 0; i < n; ++i){
        save[i].first = i;
        cin >> save[i].second;
        if(save[i].second != save[0].second){
            same = false;
        }
    }
    if(same){
        for(int i = 0; i < n; i++){
            cout << 0;
        }
        return 0;
    }
    sort(save.begin(), save.end(), val_compare);

    vector<long long> pre_s(n, 0);
    pre_s[0] = save[0].second;
    for (int i = 1; i < n; ++i){
        pre_s[i] = pre_s[i - 1] + save[i].second;
    }

    int res = 0, pos = 1e6 + 7;
    bool check = false;
    for (int i = 1; i < n - 1; ++i){
        if(pre_s[i] <= save[i + 1].second){
            check = false;
            pos = 1e6 + 7;
            continue;
        }
        check = true;
        pos = min(pos, i);
    }

    vector<int> result(n, 0);
    if(check){
        for (int i = pos; i < n; ++i){
            result[save[i].first] = 1;
        }
    }

    for(int i = 0; i < n; i++){
        cout << result[i];
    }
    
    time();
    return 0;
}