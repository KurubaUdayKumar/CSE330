#include <iostream>
#include <vector>

using namespace std;

const int MAX_ROW = 100;
const int MAX_COL = 100;
int getMaxGold(vector<vector<int>>& mine, int i, int j, int m, int n) 
{
    if (i < 0 || i >= m || j < 0 || j >= n) 
	{
        return 0;
    }
    int left = getMaxGold(mine, i + 1, j - 1, m, n);
    int down = getMaxGold(mine, i + 1, j, m, n);
    int right = getMaxGold(mine, i + 1, j + 1, m, n);
    return mine[i][j] + max(left, max(down, right));
}

int main() {
    int m, n; 
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
    for (int i = 0; i < m; i++) {
        int currentGold = getMaxGold(mine, i, 0, m, n);
        maxGold = max(maxGold, currentGold);
    }
    cout << "Maximum gold that can be collected: " << maxGold << endl;
    
    return 0;
}

