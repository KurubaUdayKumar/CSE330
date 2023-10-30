#include <bits/stdc++.h>

using namespace std;

// Function to calculate the maximum gold that can be collected
// from a given cell (i, j)
int getMaxGold(vector<vector<int>> &mine, int i, int j, int m, int n) {
    // Base case: If we are out of the grid, return 0
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return 0;
    }
    
    // Move to the next row and explore all three possible moves
    int left = getMaxGold(mine, i + 1, j - 1, m, n);
    int down = getMaxGold(mine, i + 1, j, m, n);
    int right = getMaxGold(mine, i + 1, j + 1, m, n);
    
    // Return the maximum of the three possible moves plus the gold in the current cell
    return mine[i][j] + max(left, max(down, right));
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
    
    int maxGold = 0;
    // Try starting from each cell in the first column
    for (int i = 0; i < m; i++) {
        int currentGold = getMaxGold(mine, i, 0, m, n);
        maxGold = max(maxGold, currentGold);
    }
    
    cout << "Maximum gold that can be collected: " << maxGold << endl;
    
    return 0;
}

