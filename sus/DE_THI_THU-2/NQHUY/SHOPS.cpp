// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
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

const int C = 1000000; 

int N, K;
vector<int> p;

bool check(int D) {
    for (int s = 0; s < N; ++s) {
        int i = s;
        int count = 0;
        int covered = 0;
        do {
            if (count >= K) break;
            int m = 0;
            while (m < N) {
                int j = (i + m) % N;
                ll dist = p[j] - p[i];
                if (j < i) dist += C;
                if (dist > 2LL * D) break;
                m++;
            }
            m--; 
            if (m < 0) break; 
            covered += (i <= (i + m) % N) ? m + 1 : (N - i + (i + m) % N + 1);
            i = (i + m + 1) % N;
            count++;
            if (covered >= N) return true;
        } while (count < K && i != s);
        if (covered >= N) return true;
    }
    return false;
}

signed main() {
    fastio();
    docfile();

    cin >> N;
    p.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> p[i];
    }
    cin >> K;
    
    sort(p.begin(), p.end());
    
    int low = 0, high = 500000;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (check(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    cout << low << ln;

    time();
    return 0;
}