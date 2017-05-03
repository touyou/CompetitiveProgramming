#include <cstdio>
#include <iostream>
using namespace std;

double max(double a, double b) {
	if (a > b) return a;
	return b;
}
double min(double a, double b) {
	if (a < b) return a;
	return b;
}

int main() {
	double xa1, ya1, xa2, ya2, xb1, yb1, xb2, yb2;
	while (cin>>xa1>>ya1>>xa2>>ya2>>xb1>>yb1>>xb2>>yb2) {
		if (max(xa1, xb1)<=min(xa2, xb2)&&max(ya1, yb1)<=min(ya2, yb2)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
