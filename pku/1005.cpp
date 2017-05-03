#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

bool ok(double x, double y, int year) {
	const double PI=3.1415926535897932384626433832795;
	double mile = 100*year;
	double R2 = mile/PI;
	if (pow(x,2)+pow(y,2)<R2) return false;
	return true;
}

int solve(double x, double y) {
	int ans;
	for (int i=1;;i++) {
		if (!ok(x,y,i)) {
			ans = i;
			break;
		}
	}
	return ans;
}

int main() {
	int N; cin >> N;
	double x, y;
	for (int i=0; i<N; i++) {
		cin >> x >> y;
		int ans = solve(x,y);
		cout << "Property " << i+1 << ": This property will begin eroding in year " << ans << "." << endl;
	}
	cout << "END OF OUTPUT." << endl;
}
