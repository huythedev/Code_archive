#include <bits/stdc++.h>
using namespace std;

#define NAME "ZIP"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if (ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int max_freq = 0;

string compress(string st) {
	string res = "";
	for(int i = 0; i < st.length(); ++i) {
		int tmp = 0;
		char c = st[i];
		while(st[i] == c) {
			++tmp;
			++i;
		}
		res += c + (to_string(tmp));
		--i;
		max_freq = max(max_freq, tmp);
	}
	return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
    
    string s; getline(cin, s);

    cout << compress(s) << ln << max_freq;

    return 0;
}
