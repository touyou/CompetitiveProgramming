#include <iostream>
#include <sstream>

using namespace std;

int main() {
	double mon, sum=0;
	string res = "$";
	for (int i=0; i<12; i++) {
		cin >> mon;
		sum += mon;
	}
	sum /= 12;
	stringstream ss;
	ss << sum;
	res += ss.str();
	cout << res << endl;
}
