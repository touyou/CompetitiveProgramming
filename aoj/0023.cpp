#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int n; cin >> n;
	for (int i=0; i<n; i++) {
		double ra,rb,xa,ya,xb,yb;
		cin >> xa >> ya >> ra >> xb >> yb >> rb;
		double d = 	sqrt(pow(xa-xb, 2) + pow(ya-yb, 2));
		if (d > ra + rb) {
			cout << "0" << endl;
			continue;
		}
		if (ra > rb) {
			if (d < ra - rb)
				cout << "2" << endl;
			else if (d >= ra - rb && d <= ra + rb)
				cout << "1" << endl;
		} else {
			if (d < rb - ra)
				cout << "-2" << endl;
			else if (d >= rb - ra && d <= ra + rb)
				cout << "1" << endl;
		}
	}
}
