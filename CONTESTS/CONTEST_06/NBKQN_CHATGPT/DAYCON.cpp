#include <bits/stdc++.h>
using namespace std;

ifstream fin("DAYCON.INP");
ofstream fout("DAYCON.OUT");

int main() {
    int N;
    fin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) fin >> A[i];

    long long res = 0;
    unordered_map<long long, int> mp;
    mp[0] = 1;
    long long sum = 0;
    
    for (int i = 0; i < N; i++) {
        sum += A[i];
        res += mp[sum - (i + 1)];
        mp[sum - (i + 1)]++;
    }

    fout << res << "\n";
    return 0;
}
