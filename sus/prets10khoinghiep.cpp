// Author: huythedev
// Problem Link: 
#include <bits/stdc++.h>
using namespace std;

#define NAME "prets10khoinghiep"
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

const int MOD = 1e9 + 7;

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
	long long mem = 0; // Changed int to long long
	for (int i = 0;i<a.size();i++) {
		mem = (mem * 10LL + (a[i] - '0')) % b; // Ensure intermediate calculation uses long long
	}
	return (int)mem;
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

string minus(string a, string b) {
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

int fast_pow_mod(ll base, string exp_val) {
    bool exp_is_zero = true;
    if (exp_val.empty()) { 
        exp_is_zero = false; 
    } else {
        for (char c : exp_val) {
            if (c != '0') {
                exp_is_zero = false;
                break;
            }
        }
    }

    if (exp_is_zero) {
        return 1;
    }

    base %= MOD;
    if (base < 0) base += MOD;

    if (base == 0) {
        return 0;
    }

    ll ans = 1;
    int numeric_exponent = mods(exp_val, MOD - 1);
    
    while (numeric_exponent > 0) {
        if (numeric_exponent % 2 == 1) {
            ans = (ans * base) % MOD;
        }
        base = (base * base) % MOD;
        numeric_exponent /= 2;
    }
    return (int)ans;
}

signed main() {
    fastio();
    docfile();

    ll a, b, c; cin >> a >> b >> c;
    
    string s2 = multiBig(to_string(b), to_string(c));

    cout << fast_pow_mod(a, s2) << ln;

    time();
    return 0;
}
