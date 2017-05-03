#include <stdio.h>
#include <math.h>

int solve(int n) {
	int sum = pow(pow(2, n), 2)/2+pow(2, n)*2-1;
	if (n != 1) {
		int count = 1;
		while (count < n) {
			sum+=solve(count);
			count++;
		}
	}
	return sum;
}

int main() {
	int a;
	scanf("%d", &a);
	int ans = pow(pow(2, a), 2) - solve(a);
	printf("%d", ans);
}
