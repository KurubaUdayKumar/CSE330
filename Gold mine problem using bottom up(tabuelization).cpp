#include <iostream>
#include <vector>

using namespace std;

const int MAX_ROW = 100;
const int MAX_COL = 100;

int getMaxGold(vector<vector<int>>& mine, int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));

    // Initialize the last column of dp array
    for (int i = 0; i < m; i++) {
        dp[i][n - 1] = mine[i][n - 1];
    }

    // Start from the last column and move to the first
    for (int j = n - 2; j >= 0; j--) {
        for (int i = 0; i < m; i++) {
            int right = dp[i][j + 1];
            int up = (i > 0) ? dp[i - 1][j + 1] : 0;
            int down = (i < m - 1) ? dp[i + 1][j + 1] : 0;
            dp[i][j] = mine[i][j] + max(right, max(up, down));
        }
    }

    int maxGold = 0;
    for (int i = 0; i < m; i++) {
        maxGold = max(maxGold, dp[i][0]);
    }

    return maxGold;
}

int main() {
    int m, n; // Dimensions of the grid
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> mine(m, vector<int>(n));

    cout << "Enter the elements of the grid:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mine[i][j];
        }
    }

    int maxGold = getMaxGold(mine, m, n);
    cout << "Maximum gold that can be collected: " << maxGold << endl;

    return 0;
}

