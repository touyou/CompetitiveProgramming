#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	vector<bool> std(31,false);
	for (int i=0; i<28; i++) {
		int a; cin >> a;
		std[a] = true;
	}
	for (int i=1; i<31; i++) {
		if (!std[i]) cout << i << endl;
	}
}
