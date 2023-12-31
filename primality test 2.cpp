#include <bits/stdc++.h>
 
using namespace std;
 
bool prime(int n) {
	if (n < 2)
		return false;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n != 1 && prime(n + 1))
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	return 0;
}
