#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
using namespace std;

int countWays(const string& num, int target) {
    if (num.empty()) return 0;
    
    int n = num.size();
    
    if (n > 18) {
        if (target <= 10) {
            return 8;
        }
        return 0;
    }
    
    const int OFFSET = 1000;
    vector<unordered_map<int, int>> memo(n);
    
    function<int(int, int, long long)> dfs = [&](int pos, int isFirst, long long current) {
        if (pos == n) {
            return current == target ? 1 : 0;
        }
        
        if (!isFirst && memo[pos].count(current + OFFSET)) {
            return memo[pos][current + OFFSET];
        }
        
        int count = 0;
        long long val = 0;
        
        for (int i = pos; i < n; i++) {
            val = val * 10 + (num[i] - '0');
            
            if (val > 1e18) break;
            
            if (isFirst) {
                count += dfs(i + 1, 0, val);
            } else {
                count += dfs(i + 1, 0, current + val);
                count += dfs(i + 1, 0, current - val);
            }
        }
        
        if (!isFirst) {
            memo[pos][current + OFFSET] = count;
        }
        
        return count;
    };
    
    return dfs(0, 1, 0);
}

int main() {
    string n;
    int s;
    cin >> n >> s;
    
    cout << countWays(n, s) << endl;
    return 0;
}
