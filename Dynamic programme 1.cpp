#include<bits/stdc++.h>
using namespace std;

int countWaysToSum(int n, vector<int>& numbers) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < numbers.size(); j++) {
            if (i - numbers[j] >= 0) {
                dp[i] += dp[i - numbers[j]];
            }
        }
    }

    return dp[n];
}

int main() {
    int n;  
    cout << "Enter the number (n): ";
    cin >> n;

    vector<int> numbers;
    int num;

    cout << "Enter three numbers (repetition allowed): ";
    for (int i = 0; i < 3; i++) {
        cin >> num;
        numbers.push_back(num);
    }

    int ways = countWaysToSum(n, numbers);
    cout << "Total number of ways to form " << n << " is: " << ways << endl;

    return 0;
}



