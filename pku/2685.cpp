#include <iostream>
#include <cstring>
using namespace std;
int toInt(string mcxi) {
	int tmp = 1;
	int res = 0;
	for (int i=0; i<mcxi.length(); i++) {
		if (isdigit(mcxi[i])) {
			tmp = mcxi[i] - '0';
		} else {
			int x;
			if (mcxi[i] == 'm') x = 1000;
			else if (mcxi[i] == 'c') x = 100;
			else if (mcxi[i] == 'x') x = 10;
			else x = 1;
			res += x * tmp;
			tmp = 1;
		}
	}
	return res;
}
string toStr(int num) {
	int m, c, x, i;
	string res = "";
	m = num / 1000;
	if (m != 0) {
		num -= m * 1000;
		if (m != 1) res += (m + '0');
		res += "m";
	}
	c = num / 100;
	if (c != 0) {
		num -= c * 100;
		if (c != 1) res += (c + '0');
		res += "c";
	}
	x = num / 10;
	if (x != 0) {
		num -= x * 10;
		if (x != 1) res += (x + '0');
		res += "x";
	}
	i = num;
	if (i != 0) {
		if (i != 1) res += (i + '0');
		res += "i";
	}
	return res;
}
int main() {
	int t; cin >> t;
	for (int i=0; i<t; i++) {
		string str1, str2;
		cin >> str1 >> str2;
		cout << toStr(toInt(str1)+toInt(str2)) << endl;
	}
}
