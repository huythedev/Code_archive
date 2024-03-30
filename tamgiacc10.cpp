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

	ld a, b, c;
	cin >> a >> b >> c;
	
	if(a == b && b == c) {
		cout << "Tam giac deu" << ln;
	}
	else if(a == c || b == c || a == b) {
		cout << "Tam giac can" << ln;
	}
	else if(a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) {
		cout << "Tam giac vuong" << ln;
	}
	else {
		cout << "Tam giac thuong" << ln;
	}
	
	ld p = (a + b + c) / 2.0;
	ld dientich = sqrt(p * (p-a) * (p-b) * (p-c));
	cout << fixed << setprecision(2) << dientich << ln;
	
	dientich *= 2;
	ld sum3dc = dientich / (ld)a + dientich / (ld)b + dientich / (ld)c;
	cout << sum3dc;
	

    return 0;
}