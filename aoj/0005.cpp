 /*
Write a program which computes the greatest common divisor (GCD) and the least common multiple (LCM) of given a and b (0 < a, b ≤ 2,000,000,000). You can supporse that LCM(a, b) ≤ 2,000,000,000.
  */

#include <iostream>
#include <math.h>

using namespace std;

int calc_gcj(int a, int b) {
	int A=0, B=0;
	if (a == max(a,b)) {
		A = a;
		B = b;
	} else {
		A = b;
		B = a;
	}
	if (A == B) return A;
	else return calc_gcj(B,A-B);
	return -1;
}

void solve(int a, int b) {
	int gcj = calc_gcj(a,b);
	int lcm = a/gcj*b;
	cout << gcj << " " << lcm << endl;
}

int main() {
	int a, b;
	while (cin >> a >> b) {
		solve(a,b);
	}
	return 0;
}
