#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdvirus"
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
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << ln;
}

int main() {
    fastio();
    docfile();

    int N, D; cin >> N >> D;
    
    vector<pair<int, int>> location(N);
    vector<bool> infected(N, false);
    queue<int> q;
    
    for(int i = 0; i < N; i++) {
        cin >> location[i].first >> location[i].second;
    }
    
    infected[0] = true;
    q.push(0);
    
    while(!q.empty()) {
        int current = q.front();
        q.pop();
        
        for(int i = 0; i < N; i++) {
            if(!infected[i]) {
                double dist = sqrt(pow(location[current].first - location[i].first, 2) + pow(location[current].second - location[i].second, 2));
                if(dist <= D) {
                    infected[i] = true;
                    q.push(i);
                }
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        if(infected[i]) {
            cout << "Yes" << ln;
        } else {
            cout << "No" << ln;
        }
    }

    time();
    return 0;
}