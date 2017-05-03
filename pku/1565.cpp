#include <iostream>
#include <cmath>
using namespace std;
int main() {
	string n;
	while (cin>>n && n!="0") {
		int x = n.length();
		long long res = 0;
		for (int i = 0; i < x; i++) {
			res += (n[i] - '0') * (pow(2, x - i) - 1);
		}
		cout << res << endl;
	}
}
