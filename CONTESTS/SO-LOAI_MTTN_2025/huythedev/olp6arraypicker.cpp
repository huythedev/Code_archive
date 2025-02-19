#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MAXN = 11;

ll dp[1 << MAXN][1 << 10][2];
bool vis[1 << MAXN][1 << 10][2];
vector<int> pieces;
map<int, int> color_to_idx;
int n, a, b;
int num_colors;

// Helper function to check if a color will be exclusive to White
bool will_be_exclusive(int board_mask, int pos, int color_idx) {
    for (int i = 0; i < n; i++) {
        if (i != pos && (board_mask & (1 << i)) && color_to_idx[pieces[i]] == color_idx) {
            return false;  // Another piece of same color exists
        }
    }
    return true;
}

ll solve(int board_mask, int white_colors, bool white_turn) {
    if (board_mask == 0) {
        return 0;
    }
    
    if (vis[board_mask][white_colors][white_turn]) {
        return dp[board_mask][white_colors][white_turn];
    }
    
    vis[board_mask][white_colors][white_turn] = true;
    ll& result = dp[board_mask][white_colors][white_turn];
    
    if (white_turn) {
        result = LLONG_MIN;
        for (int pos = 0; pos < n; pos++) {
            if (board_mask & (1 << pos)) {
                int color_idx = color_to_idx[pieces[pos]];
                int new_white_colors = white_colors;
                ll additional_points = 0;
                
                // Points for getting a new color first
                if (!(white_colors & (1 << color_idx))) {
                    new_white_colors |= (1 << color_idx);
                    additional_points += a;  // Points for first capture
                    
                    // Only add exclusivity points if this will be the only piece of this color
                    if (will_be_exclusive(board_mask, pos, color_idx)) {
                        additional_points += b;
                    }
                }
                
                result = max(result, 
                           solve(board_mask ^ (1 << pos), 
                                new_white_colors, 
                                false) + additional_points);
            }
        }
    } else {
        result = LLONG_MAX;
        for (int pos = 0; pos < n; pos++) {
            if (board_mask & (1 << pos)) {
                result = min(result, 
                           solve(board_mask ^ (1 << pos), 
                                white_colors, 
                                true));
            }
        }
    }
    
    return result;
}

int main() {
    cin >> n >> a >> b;
    pieces.resize(n);
    
    set<int> unique_colors;
    for (int i = 0; i < n; i++) {
        cin >> pieces[i];
        unique_colors.insert(pieces[i]);
    }
    
    num_colors = 0;
    for (int color : unique_colors) {
        color_to_idx[color] = num_colors++;
    }
    
    memset(vis, 0, sizeof(vis));
    ll result = solve((1 << n) - 1, 0, true);
    cout << result << endl;
    
    return 0;
}