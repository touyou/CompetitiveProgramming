#include <iostream>
#include "stdio.h"
using namespace std;

int main() {
	double r;
	cin >> r;
	double are = r*r*3.141592653589;
	double circ = 2*r*3.141592653589;
	printf("%f %f\n", are, circ);
}
