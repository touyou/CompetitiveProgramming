#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	double m, max_m=-1.0, min_m=1000000000;
	while (cin >> m) {
		min_m = min(min_m, m);
		max_m = max(max_m, m);
	}
	double ans = max_m - min_m;
	cout << ans << endl;
}
