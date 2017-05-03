#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;
int main() {
	int n; cin >> n;
	for (int ix=0;ix<n;ix++) {
		string num; cin >> num;
		sort(num.begin(),num.end());
		stringstream os;
		os.str(num);
		int min; os >> min;
		reverse(num.begin(),num.end());
		stringstream oss;
		oss.str(num);
		int max; oss >> max;
		cout << max-min << endl;
	}
}
