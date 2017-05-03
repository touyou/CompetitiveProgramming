#include <cstdio>
#include <cmath>
int main() {
	int x, h;
	while (scanf("%d%d", &x, &h)) {
		if (x == 0 && h == 0) break;
		double temp1 = sqrt(pow((double)h, 2) + pow((double)x*sqrt(2)/2, 2));
		double temp2 = sqrt(pow(temp1, 2) - pow((double)x/2, 2));
		double S = pow((double)x, 2) + 2.0 * temp2 * (double)x;
		printf("%.6f\n", S);
	}
}
