 /*
Your friend who lives in undisclosed country is involved in debt. He is borrowing 10-man yen from a loan shark. The loan shark adds 5% interest of the debt and rounds it to the nearest sen above week by week.

Write a program which computes the amount of the debt in n weeks. ( n ≤ 100) 
 */

#include <iostream>

using namespace std;

int main() {
	int n; cin >> n;
	int ans = 100000;
	int tmp;
	for (int i=0; i<n; i++) {
		ans *= 1.05;
		tmp = ans / 1000 * 1000;
		if (tmp != ans) ans = tmp + 1000;
	}
	cout << ans << endl;
	return 0;
}
