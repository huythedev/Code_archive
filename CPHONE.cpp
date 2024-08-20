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

    int N; cin >> N;
    map<int, int> freq;
    for(int i = 0; i < N; i++) {
        int x; cin >> x;
        freq[x]++;
    }

    int maxchon = 0;
    vector<int> res;
    for(int i = 0; i <= 1000; ++i) {
        if(maxchon < freq[i]) {
            maxchon = freq[i];
            res.clear();
            res.push_back(i);
        } 
        else if(maxchon == freq[i]) {
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());

    for(int i : res) 
        cout << i << ln;
     
    return 0;
}