#include <iostream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <fstream>

#define NAME "NAME"
#define ln '\n'

typedef long long ll;
typedef long double ld;

void docfile() {
    if(std::ifstream(NAME".inp")) {
        std::freopen(NAME".inp", "r", stdin);
        std::freopen(NAME".out", "w", stdout);
    }
}

bool namnhuan(ll n) {
    if(n % 400 == 0) {
		return true;
	}
	else if(n % 4 == 0 && n % 100 != 0) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL); std::cout.tie(NULL);
    docfile();

    ll ngay, thang, nam;
    std::cin >> ngay >> thang >> nam;

    ll n;
    std::cin >> n;

    ll sumngay = 0;
    while(n--) {
        ll t;
        std::cin >> t;
        sumngay += t;
    }

    while (sumngay > 0) {
        ll daysInMonth;

        if (thang == 2 && namnhuan(nam))
            daysInMonth = 29;
        else if (thang == 2)
            daysInMonth = 28;
        else if (thang == 4 || thang == 6 || thang == 9 || thang == 11)
            daysInMonth = 30;
        else
            daysInMonth = 31;

        if (sumngay >= daysInMonth - ngay + 1) {
            sumngay -= (daysInMonth - ngay + 1);
            ngay = 1;
            if (++thang > 12) {
                thang = 1;
                nam++;
            }
        } else {
            ngay += sumngay;
            sumngay = 0;
        }
    }

    if(nam > 1000000000) {
        std::cout << -1;
        return 0;
    }
    else {
        std::cout << ngay << " " << thang << " " << nam;
    }

    return 0;
}
