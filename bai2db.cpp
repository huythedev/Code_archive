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

    string s;
    cin >> s;

    vector<ll> vowels_pos, consonants_pos;
    for(ll i = 0; i < s.size(); ++i) {
        if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            vowels_pos.push_back(i);
        } else {
            consonants_pos.push_back(i);
        }
    }

    ll special_string_count = 0;
    for(ll i = 0; i < vowels_pos.size(); ++i) {
        for(ll j = 0; j < consonants_pos.size(); ++j) {
            if(vowels_pos[i] < consonants_pos[j]) {
                ++special_string_count;
            }
        }
    }

    for(ll i = 0; i < consonants_pos.size(); ++i) {
        for(ll j = 0; j < vowels_pos.size(); ++j) {
            if(consonants_pos[i] < vowels_pos[j]) {
                ++special_string_count;
            }
        }
    }

    cout << special_string_count;

    return 0;
}