#include <bits/stdc++.h>
using namespace std;

#define NAME "H"
#define ln "\n"

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

int main() {
    fastio();
    docfile();

    int n, m;
    cin >> n >> m;

    vector<vector<char>> matrix(n, vector<char>(m));
    vector<vector<bool>> colored(n, vector<bool>(m, false)); // To track colored cells

    // Read the matrix
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int coloringActions = 0;

    // Traverse the matrix to count coloring actions
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // If we find an uncolored '#', we need to initiate a coloring action
            if (matrix[i][j] == '#' && !colored[i][j]) {
                // Start a new coloring action
                coloringActions++;

                // Color the entire row segment
                for (int col = j; col < m && matrix[i][col] == '#'; col++) {
                    colored[i][col] = true;
                }
                
                // Now color the entire column segment
                for (int row = i; row < n && matrix[row][j] == '#'; row++) {
                    colored[row][j] = true;
                }
            }
        }
    }

    // After processing, count any remaining segments
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == '#' && !colored[i][j]) {
                coloringActions++; // Count any new segment found
                // Color down the column
                for (int row = i; row < n && matrix[row][j] == '#'; row++) {
                    colored[row][j] = true;
                }
                break; // Move to the next column
            }
        }
    }

    cout << coloringActions << ln;

    return 0;
}
