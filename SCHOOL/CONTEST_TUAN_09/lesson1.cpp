#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
std;
int main() {
    string s;int main() {
    cin >> s;;
    
    int n = s.length();
    long long result = 0;int n = s.length();
    0;
    for (int i = 0; i < n; i++) {
        int countN = 0, countA = 0, countM = 0;// Precompute prefix sums for each character type
        
        for (int j = i; j < n; j++) {
            // Count characters in the current windowfor (int i = 0; i < n; i++) {
            if (s[j] == 'N') countN++; = prefixN[i] + (s[i] == 'N' ? 1 : 0);
            else if (s[j] == 'A') countA++; : 0);
            else if (s[j] == 'M') countM++;    prefixM[i+1] = prefixM[i] + (s[i] == 'M' ? 1 : 0);
            
            // Check if all counts are equal and non-zero
            if (countN > 0 && countA > 0 && countM > 0 && countN == countA && countA == countM) {// Use a map to count states: (N-A, M-A, first_N, first_A, first_M)
                result++; int>, int> states;
            }
        } <= n; i++) {
    }tion, check all previous states
    prefixN[i], min(prefixA[i], prefixM[i])); k++) {
    cout << result << endl;ch possible count k, find how many subsequences have count k of each character
    return 0;ates[make_tuple(prefixN[i] - k, prefixA[i] - k, prefixM[i] - k, k, k)];
}
        states[make_tuple(prefixN[i], prefixA[i], prefixM[i], 0, 0)]++;    }        cout << result << endl;    return 0;}