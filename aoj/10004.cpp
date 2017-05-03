#include <iostream>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int t;
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	if (b > c) {
		t = b;
		b = c;
		c = t;
	}
	if (a > b) {
                t = a;
                a = b;
                b = t;
        }
	cout << a << " " << b << " "  << c << endl;
}
