#include <bits/stdc++.h>
using namespace std;

#define NAME "cwdsubmask"
#define ln '\n'

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

string decToBinary(ll num) {
    if (num == 0) return "0";
    
    string str;
    while (num) {
        str += (num & 1) ? '1' : '0';
        num >>= 1; 
    }
    
    reverse(str.begin(), str.end()); 
    return str;
}

void insertZeroes(string& str, const map<int, int>& zero_pos) {
    for (const auto& [pos, _] : zero_pos) {
        str.insert(str.begin() + pos, '0');
    }
}

void gen(int length, string current, vector<string>& res, const map<int, int>& zero_pos) {
    if (current.size() == length) {
        string full = current;
        insertZeroes(full, zero_pos);
        res.push_back(full);
        return;
    }

    gen(length, current + '0', res, zero_pos);
    gen(length, current + '1', res, zero_pos);
}

int main() {
    fastio();
    docfile();

    ll n;
    cin >> n;
    string s = decToBinary(n);

    int cnt = count(s.begin(), s.end(), '1');

    map<int, int> zero_pos;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '0') 
            zero_pos[i] = 1;
    }

    int length = s.size() - zero_pos.size();
    
    vector<string> res;
    gen(length, "", res, zero_pos);
    
    for (const string& st : res) {
        cout << stoll(st, nullptr, 2) << ln;
    }

    time();
    return 0;
}
