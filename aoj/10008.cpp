#include <iostream>
#include "stdio.h"
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int d = a/b;
	int r = a%b;
	double f = a/b;
	printf("%d %d %6.5f\n", d, r, f);
}
