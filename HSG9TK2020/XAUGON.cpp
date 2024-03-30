#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    getline(cin, s);

    for (ll i = 0; i < s.length(); ++i) {
        if (s[i] == s[i + 1]) {
            char current_char = s[i];
            while (i + 1 < s.length() && s[i + 1] == current_char) {
                s.erase(i + 1, 1);
            }
        }
    }

    cout << s;

    return 0;
}
