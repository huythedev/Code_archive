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

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int getDaysDiff(int day1, int month1, int year1, int day2, int month2, int year2) {
    int monthDays[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int totalDays1 = 0, totalDays2 = 0;

    for (int i = 0; i < month1 - 1; i++) {
        totalDays1 += monthDays[i];
    }
    totalDays1 += day1;
    if (isLeapYear(year1) && month1 > 2) {
        totalDays1++;
    }

    for (int i = 0; i < month2 - 1; i++) {
        totalDays2 += monthDays[i];
    }
    totalDays2 += day2;
    if (isLeapYear(year2) && month2 > 2) {
        totalDays2++;
    }

    for (int i = year1; i < year2; i++) {
        totalDays2 += isLeapYear(i) ? 366 : 365;
    }

    return totalDays2 - totalDays1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ngay_x, thang_y, nam_z;
    cin >> ngay_x >> thang_y >> nam_z;

    int days = getDaysDiff(30, 3, 2022, ngay_x, thang_y, nam_z);
    cout << days << endl;

    return 0;
}