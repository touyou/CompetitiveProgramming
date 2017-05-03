#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main() {
	vector<int> n;
	int tmp;
	while (scanf("%d", &tmp) != EOF) {
		n.push_back(tmp);
	}
	for (int i=0; i<n.size(); i++) {
		if (n[i] == 42) break;
		cout << n[i] << endl;
	}
	return 0;
}
