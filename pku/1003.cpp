#include <iostream>

using namespace std;

int main() {
	double c, tmp;
	while (cin >> c) {
		int i=1;
		double sum = 0;
		if (c == 0.0) {
			break;
		}
		while (true) {
			tmp = 1.0/(i+1);
			sum += tmp;
//			cout << tmp << endl;
			if (sum >= c) {
				break;
			}
			i++;
		}
		cout << i << " card(s)" << endl;
	}
}
