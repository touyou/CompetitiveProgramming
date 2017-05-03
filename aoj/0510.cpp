#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int A=0, B=0, tmp;
	for (int i=0; i<4; i++) {
		cin >> tmp;
		A += tmp;
	}
	for (int i=0; i<4; i++) {
		cin >> tmp;
		B += tmp;
	}
	int ans = max(A, B);
	cout << ans << endl;
}
