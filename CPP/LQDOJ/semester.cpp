#include <bits/stdc++.h>
using namespace std;

#define NAME "semester"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
	if (ifstream(NAME".inp")) {
		freopen(NAME".inp", "r", stdin);
		freopen(NAME".out", "w", stdout);
	}
}

bool isLeapYear(ll year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	docfile();

	ll day, month, year, n;
	cin >> day >> month >> year >> n;

	const int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	ll tongngay = 0;

	for (ll i = 0; i < n; i++) {
		ll days;
		cin >> days;
		tongngay += days;
	}

	while (tongngay > 0) {
		ll songay = daysInMonth[month];
		if (month == 2 && isLeapYear(year))
			songay = 29;

		ll daysToAdd = min(tongngay, songay - day + 1);
		day += daysToAdd;
		tongngay -= daysToAdd;

		if (day > songay) {
			day -= songay;
			month++;
			if (month > 12) {
				month = 1;
				year++;
				if (year > (ll)1e9) {
					cout << -1;
					return 0;
				}
			}
		}
	}

	cout << day << " " << month << " " << year;

	return 0;
}
