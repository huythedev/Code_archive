#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    string str;
    getline(cin, str);

    for (ll i = 0; i < str.length(); ++i) {
        if (str[i] - '0' >= 0 && str[i] - '0' <= 9) {
            str.erase(i, 1);
            --i;
        }
    }

    cout << str;
    return 0;
}