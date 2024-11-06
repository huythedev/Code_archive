#include <bits/stdc++.h>
using namespace std;

#define NAME "sumsubtree"
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

const int MAXN = 200005;

vector<int> adj[MAXN]; 
ll values[MAXN]; 
ll subtreeSum[MAXN]; 
bool visited[MAXN]; 

void dfs(int node) {
    visited[node] = true;
    subtreeSum[node] = values[node];

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
            subtreeSum[node] += subtreeSum[neighbor]; 
        }
    }
}

int main() {
    fastio();
    docfile();

    int N, Q;
    cin >> N >> Q;

    for (int i = 1; i <= N; i++) {
        cin >> values[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(visited, false, sizeof(visited));
    dfs(1); 

    for (int i = 0; i < Q; i++) {
        int type;
        cin >> type;
        
        if (type == 1) {
            int s, x;
            cin >> s >> x;
            ll diff = x - values[s]; 
            values[s] = x; 

            int node = s;
            while (node != -1) {
                subtreeSum[node] += diff;
                if (adj[node].empty()) break; 
                node = adj[node][0];
            }

        } else if (type == 2) { 
            int s;
            cin >> s;
            cout << subtreeSum[s] << "\n"; 
        }
    }

    time();
    return 0;
}