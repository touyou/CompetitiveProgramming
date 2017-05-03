 /*
Write a program which reads an integer n (n ≤ 999999) and prints the number of prime numbers which are less than or equal to n. A prime number is a natural number which has exactly two distinct natural number divisors: 1 and itself. For example, the first four prime numbers are: 2, 3, 5, 7.
 */

#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

 /* 
http://community.appliplanet.co.jp/community/beginner

[ポイント]
+nが素数でないならの平方根mより小さいもので割り切れるはず。
+予め２の倍数を除外する。
+数が大きくなるならばエラストテレスの篩をつかう←実装はbool[]を使う。
 */
void solve(int n) {
	bool prime[n+1];
	for (int i=0; i<n+1; i++)
		prime[i] = true;
	prime[0] = false; prime[1] = false;
	int m = (int)sqrt(n);					// nの平方根
	
	for (int i=2; i<=m; i++) {
		if(prime[i]) {
			for (int k=i*i; k<=n; k += i)
				prime[k] = false;
		}
	}
	
	int count = 0;
	for (int i=0; i<n+1; i++) {
		if (prime[i]) count++;
	}
	
	cout << count << endl;
}

int main() {
	int n;
	while (cin >> n) {
		solve(n);
	}
	return 0;
}
