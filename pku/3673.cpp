#include <iostream>
using namespace std;
int main() {
	string A, B;
	int res = 0;
	cin >> A >> B;
	for (int i = 0; i < A.length(); i++) {
		int temp = A[i] - '0';
		for (int j = 0; j < B.length(); j++) res += temp * (B[j] - '0');
	}
	cout << res << endl;
}
