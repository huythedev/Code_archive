#include <bits/stdc++.h>
#define NAME "MINMAX"
using namespace std;

typedef long long ll;

void docfile() {
	if (ifstream(NAME".inp")) {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
}

string nhonhat(string a, string b) {
	string minnum;

	while(!a.empty() || !b.empty()) {
		if (a.empty()) {
            minnum += b;
            break;
        } else if (b.empty()) {
            minnum += a;
            break;
        }

		if(a[0] < b[0]) {
			minnum += a[0];
			a.erase(0, 1);
		}
		else {
			minnum += b[0];
			b.erase(0, 1);
		}
	}

	return minnum;
}

string lonnhat(string a, string b) {
	string maxnum;

	while(!a.empty() || !b.empty()) {
		if (a.empty()) {
            maxnum += b;
            break;
        } else if (b.empty()) {
            maxnum += a;
            break;
        }

		if(a[0] > b[0]) {
			maxnum += a[0];
			a.erase(0, 1);
		}
		else {
			maxnum += b[0];
			b.erase(0, 1);
		}
	}

	return maxnum;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();
	
	string a, b;
	cin >> a >> b;

	cout << nhonhat(a, b) << endl << lonnhat(a, b);

    return 0;
}