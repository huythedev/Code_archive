#include <bits/stdc++.h>
using namespace std;

#define NAME "J"
#define ln "\n"
#define sz size()

typedef long long ll;
typedef long double ld;

void fastio() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void docfile() {
    if (ifstream(NAME ".INP")) {
        freopen(NAME ".INP", "r", stdin);
        freopen(NAME ".OUT", "w", stdout);
    }
}

void time() {
    cerr << ln << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." 
         << ln;
}

int main() {
    fastio();
    docfile();

    int n;
    string s;
    cin >> n >> s;

    int result = 0;

    for (int start = 0; start < n; start++) {
        unordered_map<char, int> freq;
        for (int end = start; end < n; end++) {
            freq[s[end]]++;
            
            // Check the frequency of characters
            int same_count = -1; // To check if all frequencies are the same
            bool is_beautiful = true;
            for (auto &[_, count] : freq) {
                if (same_count == -1) {
                    same_count = count; // Set the first character's count
                } else if (count != same_count) {
                    is_beautiful = false; // Found a different count
                    break;
                }
            }

            if (is_beautiful) {
                result++;
            }
        }
    }

    cout << result << ln;

    time();
    return 0;
}
    