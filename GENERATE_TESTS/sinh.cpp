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
            int curr = rnd(l, prev);
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
} // namespace genTest


signed main(signed argc, char* argv[]) {
    int id = atoi(argv[1]);
    
    if(id <= 60) {
        int n = genTest::rnd(1, 20), l = genTest::rnd(1, n), r = genTest::rnd(l, n);
        cout << n << " " << l << " " << r << "\n";
        vector<int> a = genTest::vec(n, 0, 10);
        genTest::print(a);
    }
    else {
        int n = genTest::rnd(1000, 100000), l = genTest::rnd(1, n), r = genTest::rnd(l, n);
        cout << n << " " << l << " " << r << "\n";
        vector<int> a = genTest::vec(n, -1000000000, 1000000000);
        genTest::print(a);
    }

    return 0;
}