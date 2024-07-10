#include <bits/stdc++.h>
using namespace std;

#define NAME "LFIB"

void fastio() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
}

void docfile() {
	if(ifstream(NAME".INP")) {
		freopen(NAME".INP", "r", stdin);
		freopen(NAME".OUT", "w", stdout);
	}
}

string sum(string a, string b) {
	string res = "";
    int carry = 0;
    int n = a.size(), m = b.size();
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int i = 0;
    for (; i < min(n, m); ++i) {
        int x = a[i] - '0';
        int y = b[i] - '0';
        int sum = x + y + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
    }
    while (i < n) {
        int sum = (a[i] - '0') + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
        ++i;
    }
    while (i < m) {
        int sum = (b[i] - '0') + carry;
        res += (sum % 10) + '0';
        carry = sum / 10;
        ++i;
    }

    if (carry > 0) 
        res += carry + '0';
    
    reverse(res.begin(), res.end());
    return res;
}

const int MAXN = 405;
vector<string> fib(MAXN);

void buildvec() {
	fib[0] = '0';
	fib[1] = '1';
	for(int i = 2; i < MAXN; ++i)
		fib[i] = sum(fib[i - 1], fib[i - 2]);
}
	
int main() {
	fastio(); docfile();

	buildvec();
	int T; cin >> T;
	while(T--) {
		int i, j; string s; cin >> i >> j >> s;
		string tmp = sum(fib[i], fib[j]);
		if(tmp == s)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
		//cout << tmp << endl;
	}
	return 0;
}
