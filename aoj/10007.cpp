#include <iostream>
using namespace std;

int main() {
	int x,y,t;
	for (;;) {
		cin >> x >> y;
		if (x == 0 && y == 0) break;
		if (x > y) {
			t = x;
			x = y;
			y = t;
		}
		cout << x << " " << y << endl;
	}
}
