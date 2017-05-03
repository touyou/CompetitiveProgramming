#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	float bn, n;
	cin >> bn;
	while (cin >> n) {
		if (n == 999) {
			cout << "End of Output" << endl;
			break;
		}
		printf("%.2f\n", n - bn);
		bn = n;
	}
}
