#include <bits/stdc++.h>
using namespace std;

#define NAME "F"
#define ln "\n"

typedef long long ll;

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

vector<vector<int>> graph;
vector<int> match;
vector<bool> visited;

bool dfs(int n) {
    for (int building : graph[n]) {
        if (visited[building]) continue;
        visited[building] = true;

        if (match[building] == -1 || dfs(match[building])) {
            match[building] = n;
            return true;
        }
    }
    return false;
}

int main() {
    fastio();
    docfile();

    int t;
    cin >> t;
    
    while (t--) {
        int n; cin >> n;
        int nA, nB, nC; cin >> nA >> nB >> nC;

        int total_buildings = nA + nB + nC;
        graph.assign(n + 1, vector<int>());

        int mA; cin >> mA;
        for(int i = 0; i < mA; i++) {
            int worker; cin >> worker;
            for(int j = 0; j < nA; j++) {
                graph[worker].push_back(j);
            }
        }

        int mB; cin >> mB;
        for(int i = 0; i < mB; i++) {
            int worker; cin >> worker;
            for(int j = nA; j < nA + nB; j++) {
                graph[worker].push_back(j);
            }
        }

        int mC; cin >> mC;
        for(int i = 0; i < mC; i++) {
            int worker; cin >> worker;
            for(int j = nA + nB; j < total_buildings; j++) {
                graph[worker].push_back(j);
            }
        }

        match.assign(total_buildings, -1);
        int res = 0;

        for(int i = 1; i <= n; i++) {
            visited.assign(total_buildings, false);
            if(dfs(i)) res++;
        }

        cout << res << ln;
    }

    return 0;
}
