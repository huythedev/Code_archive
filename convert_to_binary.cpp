#include <bits/stdc++.h>
using namespace std;

#define NAME "convert_to_binary"
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

pair<string, int> divideByTwo(const string& decimalNumber) {
    string result = "";
    int remainder = 0;
    
    for (char digit : decimalNumber) {
        int current = remainder * 10 + (digit - '0');
        result += (current / 2) + '0';
        remainder = current % 2;
    }

    result.erase(0, result.find_first_not_of('0'));
    if (result.empty()) {
        result = "0";
    }

    return {result, remainder};
}

string decimalToBinary(string decimalNumber) {
    if (decimalNumber == "0") return "0";
    
    string binaryNumber = "";
    
    while (decimalNumber != "0") {
        auto [quotient, remainder] = divideByTwo(decimalNumber);
        binaryNumber = to_string(remainder) + binaryNumber;
        decimalNumber = quotient;
    }
    
    return binaryNumber;
}

int main() {
    fastio();
    docfile();

    string decimalNumber;
    cin >> decimalNumber;

    string binaryNumber = decimalToBinary(decimalNumber);
    cout << binaryNumber << ln;

    time();
    return 0;
}
