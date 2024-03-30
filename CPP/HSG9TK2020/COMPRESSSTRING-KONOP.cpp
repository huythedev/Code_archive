#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

string nenxau(string s) {
    int n = s.length();
    string res = s;

    for (int length = 1; length <= n / 2; ++length) {
        string t = s.substr(0, length);
        int count = 1;
        string tmp = "";

        for (int i = length; i < n; i += length) {
            if (s.substr(i, length) == t) {
                count++;
            } else {
                if (count > 1) {
                    tmp += to_string(count) + t;
                } else {
                    tmp += t;
                }
                t = s.substr(i, length);
                count = 1;
            }
        }

        if (count > 1) {
            tmp += to_string(count) + t;
        } else {
            tmp += t;
        }

        if (tmp.length() < res.length()) {
            res = tmp;
        }
    }
	
	if(res == s) {
		string res1 = "1";
		res1 += res;
		return res1;
	}
	
    return res;
}

int main() {
    string st;
    cin >> st;

    string res = nenxau(st);
    cout << res << endl;

    return 0;
}
