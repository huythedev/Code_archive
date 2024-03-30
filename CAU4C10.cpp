#include <bits/stdc++.h>
using namespace std;

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(ifstream(NAME".inp")) {
        freopen(NAME".inp", "r", stdin);
        freopen(NAME".out", "w", stdout);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    docfile();
	
	int k;
	cin >> k;
	cin.ignore();
	
	string st;
	getline(cin, st);
	
	string res = "";
	for(char c : st) {
		if(c != ' ') {
			if ((int)c - k < 65) {
    			res += (char)90 - (65 - ((int)c - k + 1));
			}
			else {
    			res += (char)((int)c - k);
			}

		}
		else {
			res += " ";
		}
	}
	
	cout << res;

    return 0;
}