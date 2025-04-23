#include <bits/stdc++.h>
using namespace std;

#define int long long

namespace genTest {
    mt19937 rng((int)std::chrono::steady_clock::now().time_since_epoch().count());

    int rnd(int l, int r) {
        return uniform_int_distribution<int>(l, r)(rng);
    }

    // Hàm tạo ký tự ngẫu nhiên trong đoạn [l, r]
    char ch(char l = 'A', char r = 'Z') {
        return (char)uniform_int_distribution<int>(l, r)(rng);
    }

    // Hàm tạo chuỗi ngẫu nhiên có độ dài `len`, từ ký tự trong đoạn [l, r]
    string str(int len, char l = 'A', char r = 'Z') {
        string result;
        for (int i = 0; i < len; i++) {
            result += ch(l, r);
        }
        return result;
    }

    // Hàm tạo vector ngẫu nhiên chứa các số trong khoảng [l, r]
    vector<int> vec(int len, int l, int r) {
        vector<int> result(len);
        for (int i = 0; i < len; i++) {
            result[i] = rnd(l, r);
        }
        return result;
    }

    // Hàm tạo dãy không giảm
    vector<int> nonDecSeq(int n, int l, int r) {
        vector<int> seq;
        int prev = rnd(l, r);
        seq.push_back(prev);

        for (int i = 1; i < n; i++) {
            int curr = rnd(prev, r);
            seq.push_back(curr);
            prev = curr;
        }

        return seq;
    }

    // Hàm tạo dãy không tăng
    vector<int> nonIncSeq(int n, int l, int r) {
        vector<int> seq;
        int prev = rnd(l, r);
        seq.push_back(prev);

        for (int i = 1; i < n; i++) {
            int curr = rnd(prev, l);
            seq.push_back(curr);
            prev = curr;
        }

        return seq;
    }

    // Hàm tạo vector ngẫu nhiên chứa các phần tử từ một vector
    template <typename T>
    vector<T> vec(int len, const vector<T>& elements) {
        if (elements.empty()) throw invalid_argument("Elements vector is empty");
        vector<T> result(len);
        for (int i = 0; i < len; i++) {
            result[i] = elements[rnd(0, elements.size() - 1)];
        }
        return result;
    }

    // Hàm tạo hoán vị ngẫu nhiên của các số từ 1 đến n
    vector<int> perm(int n) {
        vector<int> v(n);
        iota(v.begin(), v.end(), 1);
        shuffle(v.begin(), v.end(), rng);
        return v;
    }

    // Hàm quá tải: Xáo trộn các phần tử trong một vector đã cho
    template <typename T>
    vector<T> perm(vector<T> v) {
        shuffle(v.begin(), v.end(), rng);
        return v;
    }

    // Hàm in vector ra màn hình
    template <typename T>
    void print(const vector<T>& v) {
        for (const T& element : v) {
            cout << element << " ";
        }
        cout << "\n";
    }

    char randomColor() {
        string colors = "GBYR";
        return colors[rnd(0, 3)];
    }

    string generateString(int n) {
        string s;
        for(int i = 0; i < n; i++) {
            s += randomColor();
        }
        return s;
    }

    // Generate a random graph with n vertices and m edges
    vector<pair<int,int>> generateGraph(int n, int m) {
        vector<pair<int,int>> edges;
        set<pair<int,int>> used;
        
        while (edges.size() < m) {
            int u = rnd(1, n);
            int v = rnd(1, n);
            
            if (u == v) continue; // no self loops
            
            // normalize edge representation (smaller vertex first)
            if (u > v) swap(u, v);
            
            // check if edge already exists
            if (used.count({u, v})) continue;
            
            used.insert({u, v});
            edges.push_back({u, v});
        }
        return edges;
    }

    // Generate a random tree with n vertices
    vector<pair<int, int>> randomTree(int n) {
        vector<pair<int, int>> edges;
        vector<int> nodes(n - 1);
        for (int i = 0; i < n - 1; i++) {
            nodes[i] = i + 2; // Nodes from 2 to n
        }
        
        // Shuffle the nodes to create random connections
        shuffle(nodes.begin(), nodes.end(), rng);
        
        for (int i = 0; i < n - 1; i++) {
            // Connect each node to a random existing node (1 to nodes[i]-1)
            int parent = rnd(1, nodes[i] - 1);
            edges.push_back({parent, nodes[i]});
        }
        
        return edges;
    }
    
    // Generate a star tree with n vertices (all connected to node 1)
    vector<pair<int, int>> starTree(int n) {
        vector<pair<int, int>> edges;
        for (int i = 2; i <= n; i++) {
            edges.push_back({1, i});
        }
        return edges;
    }
    
    // Generate a line tree with n vertices (forming a single line)
    vector<pair<int, int>> lineTree(int n) {
        vector<pair<int, int>> edges;
        for (int i = 1; i < n; i++) {
            edges.push_back({i, i + 1});
        }
        return edges;
    }
    
    // Generate a binary tree with n vertices
    vector<pair<int, int>> binaryTree(int n) {
        vector<pair<int, int>> edges;
        for (int i = 1; i <= n / 2; i++) {
            if (2 * i <= n) edges.push_back({i, 2 * i});
            if (2 * i + 1 <= n) edges.push_back({i, 2 * i + 1});
        }
        return edges;
    }
    
    // Generate a more balanced random tree with n vertices
    vector<pair<int, int>> balancedTree(int n) {
        vector<pair<int, int>> edges;
        for (int i = 2; i <= n; i++) {
            // Connect to a random node with a lower index, but limit maximum tree depth
            int parent = max(1LL, i - genTest::rnd(1, min(100LL, i-1)));
            edges.push_back({parent, i});
        }
        return edges;
    }
    
    // Generate a wide tree with limited depth (suitable for large n)
    vector<pair<int, int>> wideTree(int n) {
        vector<pair<int, int>> edges;
        int maxDepth = min((long long)20, (int)sqrt(n) + 5); // Limit tree depth based on size
        vector<int> levels(n + 1, 0);
        levels[1] = 1; // Root at level 1
        
        for (int i = 2; i <= n; i++) {
            // Choose a random parent from nodes that haven't reached max children
            int parent;
            do {
                parent = rnd(1, i-1);
            } while (levels[parent] >= maxDepth);
            
            edges.push_back({parent, i});
            levels[i] = levels[parent] + 1;
        }
        return edges;
    }
} // namespace genTest


signed main(signed argc, char* argv[]) {
    int id;
    
    // Check if command-line argument exists
    if (argc > 1) {
        id = atoi(argv[1]);
    } else {
        // Default to test case 1 if no argument provided
        id = 1;
    }
    
    if (id <= 40) {
        int n = genTest::rnd(1, 20);
        vector<int> a = genTest::vec(n, 1, 1e5);
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    else if (id <= 80) {
        int n = genTest::rnd(1, 2000);
        vector<int> a = genTest::vec(n, 1, 1e5);
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    else {
        int n = genTest::rnd(1, 2e5);
        vector<int> a = genTest::vec(n, 1, 1e5);
        cout << n << "\n";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}