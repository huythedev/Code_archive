#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<string> fir_w{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"};

    vector<string> sec_w{"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

    ll n;
    cin >> n;

    if (n <= 20) {
        cout << fir_w[n];
    } 
    else if (n / 10 != 0 && n % 10 == 0) {
    	cout << sec_w[n / 10 - 2];
    }
    else {
        cout << sec_w[n / 10 - 2] << "-" << fir_w[n % 10];
    }

    return 0;
}
