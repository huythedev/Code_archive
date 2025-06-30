// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "hamming"
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

string divs(string a,int b) {
	int s,mem = 0;
	string c = "";
	for (int i = 0;i<a.size();i++) {
		mem = mem*10 + a[i] - 48;
		s = mem/b;
		mem = mem % b;
		c = c + char(s+48);
	}
	while(c.size() > 1 && c[0] == '0') c.erase(0,1);
	return c;
}

int mods(string a,int b) {
	int mem = 0;
	for (int i = 0;i<a.size();i++) {
		mem = (mem*10 + a[i] - 48) % b;
	}
	return mem;
}

string sum(string a,string b) {
	string c = "";
	int res = 0, mem = 0;
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size() - 1;i>=0;i--) {
		res = a[i] + b[i] - 96 + mem;
		mem = res / 10;
		c = char(res%10 + 48) + c;
	}
	if (mem != 0) c = "1" + c;
	return c;
}

string hieu(string a, string b) {
    while (a.size() > b.size()) b = "0" + b;
    while (a.size() < b.size()) a = "0" + a;
    int s;
    string c = "";
    int mem = 0;
    for (int i=a.size()-1; i>=0; i--) {
        s = a[i] - b[i] - mem;
        if (s < 0) {
            s += 10;
            mem = 1;
        }
        else mem = 0;
        c = char(s+48) + c;
    }
    while ((c.size() > 1) && c[0] == '0') c.erase(0, 1);
    return c;
}

string multi(string a,int k) {
	string c = "";
	int mem = 0,s;
	for (int i = a.size() - 1;i>=0;i--) {
		s = (a[i] - 48) * k + mem;
		mem = s/10;
		c = char(s%10 + 48) + c;
	}
	string tmp;
	if (mem > 0) tmp = to_string(mem);
	else tmp = "";
	c = tmp + c;
	return c;
}

string multiBig(string a,string b) {
	string s = "",tmp;
	int m = -1;
	for (int i = a.size() - 1;i>=0;i--) {
		m++;
		tmp = multi(b,a[i]-48);
		for (int j = 1;j<=m;j++) tmp = tmp + '0';
		s = sum(s,tmp);
	}
	return s;
}

void subtask2() {
    ll m, n;
    cin >> m >> n;
    string a, b;
    cin >> a >> b;
    
    ll len_a = a.length();
    ll len_b = b.length();
    
    if (len_a == len_b) {
        ll diff_per_cycle = 0;
        for (int i = 0; i < len_a; i++) {
            if (a[i] != b[i]) diff_per_cycle++;
        }
        cout << diff_per_cycle * m << "\n";
        return;
    }
    
    vector<int> freq_a(26, 0), freq_b(26, 0);
    for (char c : a) freq_a[c - 'a']++;
    for (char c : b) freq_b[c - 'a']++;
    
    ll same_chars = 0;
    for (int i = 0; i < 26; i++) {
        same_chars += (ll)freq_a[i] * freq_b[i];
    }
    
    __int128_t lcm = (__int128_t)len_a * len_b;
    __int128_t total_len = (__int128_t)m * len_a;
    __int128_t diff_in_lcm = lcm - same_chars;
    __int128_t num_blocks = total_len / lcm;
    
    ll result = (ll)(diff_in_lcm * num_blocks);
    cout << result << ln;
}

void solve() {
    int subtask; cin >> subtask;

    if (subtask == 2) {
        subtask2();
        return;
    }

    ll m, n; cin >> m >> n;
    string a, b; cin >> a >> b;

    ll aLen = a.length(), bLen = b.length();
    ll common_div = gcd(aLen, bLen);

    string lcm = divs(to_string(aLen), common_div);
    lcm = multiBig(lcm, to_string(bLen));

    vector<vector<int>> vec(common_div, vector<int>(26, 0));
    for (int i = 0; i < aLen; ++i)
        vec[i % common_div][a[i] - 'a']++;

    string diff = "0";
    string total = divs(to_string(aLen), common_div);

    for (int i = 0; i < bLen; ++i) {
        int idx = b[i] - 'a';
        int remainder = i % common_div;
        int same_chars = vec[remainder][idx];
        string st = to_string(same_chars);
        
        while (st.length() < total.length())
            st = "0" + st;

        string diff2 = hieu(total, st);
        diff = sum(diff, diff2);
    }

    string total_len = multiBig(to_string(m), to_string(aLen));

    string res = multiBig(diff, divs(total_len, stoi(lcm)));

    while (res.length() > 1 && res[0] == '0')
        res.erase(0, 1);

    cout << res << ln;
}

signed main() {
    docfile();
    fastio();

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}