#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int T; cin >> T;
	for (int i=0; i<T; i++) {
		int N; cin >> N;
		int c = 0;
		for (int b=N; b>=6; b--) {
			for (int a=b-1; a>sqrt(b); a--) {
				if ((a*b)%(a+b)==0) {
					c++;
				}
			}
		}
		cout << c << endl;
	}
	return 0;
}
