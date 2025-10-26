// Author: NBK.VaiLatXucXich
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void fileIO() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

string sum(string a,string b) {
	string c = "";
	int res = 0, mem = 0;
	while (a.size() < b.size()) a = "0" + a;
	while (a.size() > b.size()) b = "0" + b;
	for (int i = a.size() - 1; i >= 0; i--) {
		res = a[i] + b[i] - 96 + mem;
		mem = res / 10;
		c = char(res % 10 + 48) + c;
	}
	if (mem != 0) c = "1" + c;
	return c;
}

string multi(string a,int k) {
	string c = "";
	int mem = 0, s;
	for (int i = a.size() - 1; i >= 0; i--) {
		s = (a[i] - 48) * k + mem;
		mem = s / 10;
		c = char(s % 10 + 48) + c;
	}
	string tmp;
	if (mem > 0) tmp = to_string(mem);
	else tmp = "";
	c = tmp + c;
	return c;
}

string multiBig(string a,string b) {
	string s = "", tmp;
	int m = -1;
	for (int i = a.size() - 1; i >= 0; i--) {
		m++;
		tmp = multi(b, a[i] - 48);
		for (int j = 1; j <= m; j++) tmp = tmp + '0';
		s = sum(s,tmp);
	}
	return s;
}

string subtract(string a,string b) {
	string c = "";
	while (b.size() < a.size()) b = "0" + b;
	int mem = 0;
	for (int i = a.size() - 1; i >= 0; i--) {
		int diff = (a[i] - 48) - (b[i] - 48) - mem;
		if (diff < 0) {
			diff += 10;
			mem = 1;
		}
        else {
            mem = 0;
        }

		c = char(diff + 48) + c;
	}

	ll fi = c.find_first_not_of('0');
	if (fi != string::npos) return c.substr(fi);
    
	return "0";
}

bool ok(string a,string b) {
	if (a.size() != b.size()) return a.size() > b.size();
	return a >= b;
}

pair<string,string> divide(string a, string b) {
	if (!ok(a, b)) return {"0", a};

	string q = "", cur = "";
	for (char ch : a) {
		cur += ch;
		ll fi = cur.find_first_not_of('0');
		if (fi != string::npos) cur = cur.substr(fi);
		else cur = "0";
		
		int cnt = 0;
		while (ok(cur, b)) {
			cur = subtract(cur, b);
			cnt++;
		}
		q += to_string(cnt);
	}

	ll fi = q.find_first_not_of('0');
	if (fi != string::npos) q = q.substr(fi);
	else q = "0";

	fi = cur.find_first_not_of('0');
	if (fi != string::npos) cur = cur.substr(fi);
	else cur = "0";

	return {q, cur};
}

string gcdStr(string a, string b) {
	while (b != "0") {
		string t = b;
		b = divide(a, b).second;
		a = t;
	}
	return a;
}

string binpow(string a, ll n){
	if (n == 0)
		return "1";
    
	string res = binpow(a, n / 2);
	string res2 = multiBig(res, res);

	if (n % 2 == 1)
		return multiBig(res2, a);
	else
		return res2;
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

string pow(int base, int exp) {
    string res = "1";
    for (int i = 0; i < exp; ++i) 
        res = multi(res, base);
    return res;
}

int calc(int x, int p) { 
    int res = 0; 
    while (x % p == 0) { 
        x /= p;
        ++res; 
    } 
    return res; 
}

int gcd(int a, int k, int n) {
    int g = 1;
    for (int p = 2; 1LL * p * p <= k; ++p) {
        if (k % p == 0) {
            int e1 = 0; 
            while (k % p == 0) { 
                k /= p; 
                ++e1; 
            }

            int e2 = calc(a, p);
            int e3  = min(e2, e1 * n);
            while (e3--) 
                g *= p;
        }
    }

    if (k > 1) {
        int p = k;
        int e1 = calc(a, p);
        int e2  = min(e1, n);
        while (e2--) 
            g *= p;
    }

    return g;
}

void solve() {
    int N, K;
    cin >> N >> K;
    
    if (N > K) {
        cout << "0 1" << ln;
        return;
    }
    
    int tmp = K - N + 1;
    int g = gcd(tmp, K, N);

    string A = pow(K + 1, N - 1);
    A = multi(A, tmp / g);

    string B = pow(K, N);
    B = divs(B, g);

    cout << A << ' ' << B << ln;
}

signed main() {
    fastIO();
    fileIO();

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    time();
    return 0;
}
